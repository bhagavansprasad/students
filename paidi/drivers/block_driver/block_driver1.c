/*
 * A sample, extra-simple block driver. Updated for kernel 2.6.31.
 *
 * (C) 2003 Eklektix, Inc.
 * (C) 2010 Pat Patterson <pat at superpat dot com>
 * Redistributable under the terms of the GNU GPL.
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>

MODULE_LICENSE("Dual BSD/GPL");
static char *Version = "1.4";

static int major_num = 0;
module_param(major_num, int, 0);
static int logical_block_size = 512;
module_param(logical_block_size, int, 0);
static int nsectors = 1024; /* How big the drive is */
module_param(nsectors, int, 0);

/*
 * We can tweak our hardware sector size, but the kernel talks to us
 * in terms of small sectors, always.
 */
#define KERNEL_SECTOR_SIZE 512

/*
 * Our request queue.
 */
static struct request_queue *Queue;

/*
 * The internal representation of our device.
 */
static struct sbd_device
{
    unsigned long size;
    spinlock_t lock;
    u8 *data;
    struct gendisk *gd;
} Device;

/*
 * Handle an I/O request.
 */
static void sbd_transfer(struct sbd_device *dev, sector_t sector, unsigned long nsect, char *buffer, int write)
{
    unsigned long offset = sector * logical_block_size;
    unsigned long nbytes = nsect * logical_block_size;

    printk (KERN_NOTICE "3. sbd_transfer\n");

    if ((offset + nbytes) > dev->size)
    {
        printk (KERN_NOTICE "sbd: Beyond-end write (%ld %ld)\n", offset, nbytes);
        return;
    }

    if (write)
        memcpy(dev->data + offset, buffer, nbytes);
    else
        memcpy(buffer, dev->data + offset, nbytes);
}

static void sbd_request(struct request_queue *q)
{
    struct request *req;

    printk (KERN_NOTICE "2. sbd_request\n");
    req = blk_fetch_request(q);
    while (req != NULL)
    {
        if (!blk_fs_request(req))
        {
            printk (KERN_NOTICE "Skip non-CMD request\n");
            __blk_end_request_all(req, -EIO);
            continue;
        }

        sbd_transfer(&Device, blk_rq_pos(req), blk_rq_cur_sectors(req), req->buffer, rq_data_dir(req));

        if ( ! __blk_end_request_cur(req, 0) )
        {
            req = blk_fetch_request(q);
        }
    }
}

/*
 * The HDIO_GETGEO ioctl is handled in blkdev_ioctl(), which
 * calls this. We need to implement getgeo, since we can't
 * use tools such as fdisk to partition the drive otherwise.
 */
int sbd_getgeo(struct block_device * block_device, struct hd_geometry * geo)
{
    long size;

    printk (KERN_NOTICE "4. sbd_getgeo\n");
    /* We have no real geometry, of course, so make something up. */
    size = Device.size * (logical_block_size / KERNEL_SECTOR_SIZE);
    geo->cylinders = (size & ~0x3f) >> 6;
    geo->heads = 4;
    geo->sectors = 16;
    geo->start = 0;
    return 0;
}

/*
 * The device operations structure.
 */
static struct block_device_operations sbd_ops =
{
    .owner  = THIS_MODULE,
    .getgeo = sbd_getgeo
};

static int __init sbd_init(void)
{
    /*
     * Set up our internal device.
     */
    printk (KERN_NOTICE "1. sbd_init\n");
    Device.size = nsectors * logical_block_size;
    spin_lock_init(&Device.lock);
    Device.data = vmalloc(Device.size);
    if (Device.data == NULL)
        return -ENOMEM;
    /*
     * Get a request queue.
     */
    Queue = blk_init_queue(sbd_request, &Device.lock);
    if (Queue == NULL)
        goto out;
    blk_queue_logical_block_size(Queue, logical_block_size);
    /*
     * Get registered.
     */
    major_num = register_blkdev(major_num, "sbd");
    printk(KERN_WARNING "device is registred :%d\n", major_num);
    if (major_num <= 0)
    {
        printk(KERN_WARNING "sbd: unable to get major number\n");
        goto out;
    }
    /*
     * And the gendisk structure.
     */
    Device.gd = alloc_disk(16);
    if (!Device.gd)
        goto out_unregister;
    Device.gd->major = major_num;
    Device.gd->first_minor = 0;
    Device.gd->fops = &sbd_ops;
    Device.gd->private_data = &Device;
    strcpy(Device.gd->disk_name, "sbd0");
    set_capacity(Device.gd, nsectors);
    Device.gd->queue = Queue;
    add_disk(Device.gd);

    return 0;

out_unregister:
    unregister_blkdev(major_num, "sbd");
out:
    vfree(Device.data);
    return -ENOMEM;
}

static void __exit sbd_exit(void)
{
    printk (KERN_NOTICE "5. sbd_exit\n");
    del_gendisk(Device.gd);
    put_disk(Device.gd);
    unregister_blkdev(major_num, "sbd");
    blk_cleanup_queue(Queue);
    vfree(Device.data);
}

module_init(sbd_init);
module_exit(sbd_exit);

