#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define SUCCESS 0
#define DEVICE_NAME "chardev"
#define BUF_LEN 80

int init_module(void);
void cleanup_module(void);

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);

static int Major;

static int Device_Open = 0;


static struct file_operations fops= {
	.open  = device_open,
	.release=device_release

};

int init_module(void)
{
	Major = register_chrdev(0, DEVICE_NAME, &fops);

	if(Major<0)
	{
		printk(KERN_ALERT"Registering char device failed with %d \n\r ",Major);
		return Major;
	}
	printk(KERN_INFO"mknod /dev/%s c %d 0\n\r ",DEVICE_NAME, Major);
	return SUCCESS;
}



void cleanup_module(void)
{
	unregister_chrdev(Major, DEVICE_NAME);
	printk("-->cleanup_module is called\n");
}



static int device_open(struct inode *inode,struct file *file)
{
	printk("-->device_open is called\n");

	if(Device_Open)
		return -EBUSY;

	return SUCCESS;
}

static int device_release(struct inode *inode, struct file * fike)
{
	printk("-->device_release is called\n");
	Device_Open--;

	module_put(THIS_MODULE);

	return 0;

}
