#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static ssize_t device_read(struct file * , char * , loff_t  *);
static int device_release(struct inode * , struct file *);
static int device_write(struct file * , const char * , size_t , loff_t *);

#define SUCESS 0
#define DEVICE_NAME  "chardev"
#define BUF_LEN 80


static int Major;
static int Device_open = 0;
static char msg[BUF_LEN];
static char *msg_ptr;

static struct file_operationsfops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};



int init_module(void)
{
	Major = register_chrdev(0 ,DEVICE_NAME , &fops);
	
	if(Major < 0)
	{
		printk(KERN_ALERT "registering char device failed with-> %d\n",Major);
		return Major;
	}
	printk(KERN_INFO "i was assigned major number %d. to talk to \n",Major);
	printk(KERN_INFO "the driver , create a dev file with \n");
	printk(KERN_INFO "mknod /dev/% c%d 0. \n",DEVICE_NAME,Major);
	printk(KERN_INFO "try various minor numbers .try to cat and echo to\n");
	printk(KERN_INFO "the device file.\n");
	printk(KERN_INFO "remove the device file and module when done .\n");
	return SUCESS;
}



void cleanup_module(void)
{
	int ret = unregister_chrdev(Major , DEVICE_NAME);
	if(ret < 0)
		printk(KERN_ALERT "ERROR in unregister_chrdev  %d\n",ret);
		
}

static int device_open(struct inode *inode, struct file *file)
{
	static int counter = 0;

	if (Device_Open)
		return -EBUSY;

	Device_Open++;
	sprintf(msg, "I already told you %d times Hello world!\n", counter++);
	msg_Ptr = msg;
	try_module_get(THIS_MODULE);

	return SUCCESS;
}

static int device_release(struct inode *inode , struct file *file)
{
	Device_Open--;
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t device_read(struct file *filp , char *buffer , size_t length ,loff_t *offset)
{
	int bytes_read = 0;
	if(*msg_ptr == 0)
		return 0;
	while(length && *msg_ptr)
	{
		put_user(*(msg_ptr++),buffer++);
		length--;
		bytes_read++;
	}
}


static ssize_t

device_write(struct *filp , const char *buff .size_t len , loff_t *off)
{
	printk(KERN_ALERT "sorry, this operation isn't supported .\n");
	return -EINVAL;
}
