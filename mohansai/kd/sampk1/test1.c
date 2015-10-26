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
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

static int Major;

static int Device_Open = 0;

static char msg[BUF_LEN];
static char *msg_Ptr;

static struct file_operations fops= {
	.read  = device_read,
	.write = device_write,
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

	printk(KERN_INFO"I was assigned major number %d to talking to\n\r ",Major);
	printk(KERN_INFO"The driver create a dev file with \n\r");
	printk(KERN_INFO"mknod /dev/%s c %d 0\n\r ",DEVICE_NAME, Major);
	printk(KERN_INFO"Try various minor number try to cat and echo to \n\r");
	printk(KERN_ALERT"The device file \n\r ");
	printk(KERN_INFO"Remove the device file mode and module when done \n \r" );

	return SUCCESS;
}



void cleanup_module(void)
{
	unregister_chrdev(Major, DEVICE_NAME);
	printk("-->cleanup_module is called\n");
#if 0
	int ret = (int )unregister_chrdev(Major, DEVICE_NAME);

	if(ret < 0)
		printk(KERN_ALERT "Error in unregister_chardev: %d\n ",ret);
#endif
}



static int device_open(struct inode *inode,struct file *file)
{
	static int count=0;

	printk("-->device_open is called\n");

	if(Device_Open)
		return -EBUSY;

	Device_Open++;
	sprintf(msg,"I already told you  %d times hellow world \n ",count++);
	msg_Ptr=msg;
	try_module_get(THIS_MODULE);

	return SUCCESS;
}

static int device_release(struct inode *inode, struct file * fike)
{
	printk("-->device_release is called\n");
	Device_Open--;

	module_put(THIS_MODULE);

	return 0;

}

static ssize_t device_read(struct file *filp, char *buffer,	size_t length,loff_t * offset)
{
	int bytes_read = 0;

	printk("-->device_read is called\n");

	if (*msg_Ptr == 0)
		return 0;

	while (length && *msg_Ptr)
	{

		put_user(*(msg_Ptr++), buffer++);

		length--;
		bytes_read++;
	}

	return bytes_read;
}


static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
	printk("-->device_write is called\n");
	printk(KERN_ALERT "Sorry, this operation isn't supported.\n");
	return 3;
}
