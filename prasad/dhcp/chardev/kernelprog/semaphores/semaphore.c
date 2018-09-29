#include "linux/module.h"
#include "linux/init.h"
#include "linux/fs.h"
#include "linux/slab.h"
#include "asm/semaphore.h"

MODULE_LICENSE("GPL");

static int major;
static struct semaphore sem;

int devciceopen(struct inode *inode, struct file *filp)
{     
    printk("cat is opened this file\r\n");
    return 0;
}

int devicerelease(struct inode *inode, struct file *file)
{

    printk("cat is closed this file\r\n");
    return 0;
}

ssize_t deviceread(struct file *flip, char *buf, size_t count, loff_t *fops)
{
    if( down_interruptible(&sem))
	return -1;
    printk("Reading function invoked. semaphore acquired.\n\n");
    printk("To release semaphore, ionvoke dummy write function on device \n");
    printk("Example :echo 'abc' > /dev/mydevice \n");
    printk("semaphore count in deviceread : %lu \r\n",count);
    return 0;
}

ssize_t devicewrite(struct file *file, const char *buf, size_t count, loff_t *fops)
{
    printk("Write function invoked. Releasing semaphore. \n");
    up(&sem); 
    printk("semaphore count  in devicewrite: %lu \r\n",count);
    return count;
}


struct file_operations fops =
{

open: devciceopen,
      release:devicerelease,
      read:deviceread,
      write:devicewrite,
      owner:THIS_MODULE,
};

int init_module(void)
{
    major = register_chrdev(0, "mydeivce", &fops);

    if( major < 0)
    {
	printk("error in registering driver\r\n");
	return -1;
    }
    printk("Successfully registered mydevice major = %d\r\n",major);

    sema_init(&sem,1);

    return 0;

}

void cleanup_module(void)
{
    unregister_chrdev(major, "mydevice");

    printk("Unloading module mydevice\r\n");
}


