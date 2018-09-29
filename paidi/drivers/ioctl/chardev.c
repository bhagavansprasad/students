#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#include "chardev.h"
#define  SUCCESS 0
#define DEVICE_NAME "char_dev"
#define  BUF_LEN 80

static int Device_open = 0;
static char Message [BUF_LEN];
static char *Message_ptr;

static int device_open(struct inode *inode,struct file *file)
{
    printk("device_open enterd\n");
#ifdef DEBUG
	printk(KERN_INFO "device_open(%p)\n",file);
#endif

	if(Device_open)
		return -EBUSY;
	Device_open++;
	Message_ptr = Message;
	try_module_get(THIS_MODULE);
    printk("device_open return\n");
	return SUCCESS;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk("device_release enterd\n");
#ifdef  DEBUG
	printk(KERN_INFO "device_release(%p,%p)\n",inode,file);
#endif
	Device_open--;
	module_put(THIS_MODULE);
    printk("device_release return\n");
	return SUCCESS;
}

static ssize_t device_read(struct file *file,char __user *buffer,size_t length,loff_t * offset)
{
    printk("device_read enterd\n");
	int bytes_read = 0;
#ifdef DEBUG
	printk(KERN_INFO "device_read(%p,%p,%d)\n",file,buffer,length);
#endif
	if (*Message_ptr == 0)
		return 0;
	while (length && *Message_ptr)
	{
		put_user(*(Message_ptr++),buffer++);
		length--;
		bytes_read++;
	}
#ifdef DEBUG
	printk(KERN_INFO "read %d bytes, %d left\n",bytes_read,length);
#endif
    printk("device_read return\n");
	return bytes_read;
}

	static ssize_t
device_write(struct file *file,const char __user *buffer, size_t length, loff_t * offset)
{
	int i;

    printk("device_write enterd\n");
#ifdef DEBUG
	printk(KERN_INFO "device_write(%p,%s,%d)", file, buffer, length);
#endif

	for (i = 0; i < length && i < BUF_LEN; i++)
		get_user(Message[i], buffer + i);

	Message_ptr = Message;

    printk("device_write return\n");
	return i;
}

int device_ioctl(struct inode *inode,
		struct file *file,
		unsigned int ioctl_num,
		unsigned long ioctl_param)
{
	int i;
	char *temp;
	char ch;

    printk("device_ioctl enterd\n");
	switch (ioctl_num) {
		case IOCTL_SET_MSG:
			temp = (char *)ioctl_param;

			get_user(ch, temp);
			for (i = 0; ch && i < BUF_LEN; i++, temp++)
				get_user(ch, temp);

			device_write(file, (char *)ioctl_param, i, 0);
			break;

		case IOCTL_GET_MSG:
			i = device_read(file, (char *)ioctl_param, 99, 0);

			put_user('\0', (char *)ioctl_param + i);
			break;

		case IOCTL_GET_NTH_BYTE:
			return Message[ioctl_param];
			break;
	}

    printk("device_ioctl return\n");
	return SUCCESS;
}

struct file_operations Fops = {
	.read = device_read,
	.write = device_write,
	.ioctl = device_ioctl,
	.open = device_open,
	.release = device_release,
};

int init_module()
{
	int ret_val;
    printk("init_module return\n");

	ret_val = register_chrdev(MAJOR_NUM, DEVICE_NAME, &Fops);

	if (ret_val < 0) {
		printk(KERN_ALERT "%s failed with %d\n",
				"Sorry, registering the character device ", ret_val);
		return ret_val;
	}

	printk(KERN_INFO "%s The major device number is %d.\n",
			"Registeration is a success", MAJOR_NUM);
	printk(KERN_INFO "If you want to talk to the device driver,\n");
	printk(KERN_INFO "you'll have to create a device file. \n");
	printk(KERN_INFO "We suggest you use:\n");
	printk(KERN_INFO "mknod %s c %d 0\n", DEVICE_FILE_NAME, MAJOR_NUM);
	printk(KERN_INFO "The device file name is important, because\n");
	printk(KERN_INFO "the ioctl program assumes that's the\n");
	printk(KERN_INFO "file you'll use.\n");

	return 0;
}

void cleanup_module()
{

	 unregister_chrdev(MAJOR_NUM, DEVICE_NAME);

}


