#include"linux/kernel.h"
#include"linux/module.h"
#include"linux/fs.h"
#include"asm/uaccess.h"

#include"chardev.h"
#define SUCCESS 0
#define DEVICE_NAME "char_dev"
#define BUF_LEN 80

static int Device_open = 0;

static char message[BUF_LEN];

static char *message_ptr;


static int device_open(struct inode *inode, struct file *file)
{
#ifdef DEBUG
	printk(KERN_INFO "device_open(%p)\n", file);
#endif
	printk(KERN_INFO "device_open(%lu)\n", inode->i_ino);
	if(Device_open)
		return -EBUSY;

	Device_open++;

	message_ptr = message;

	try_module_get(THIS_MODULE);
	return SUCCESS;
}

static int device_release(struct inode *inode, struct file *file)
{
#ifdef DEBUG
	printk(KERN_INFO "device_release(%p,%p)\n",inode,file);
#endif

	Device_open--;

	module_put(THIS_MODULE);
	return SUCCESS;

}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length , loff_t *offset)
{
	int byte_read = 0;
	char buff[] = "this is kernel  written message to user process"; 
#ifdef DEBUG
	printk(KERN_INFO "device_read(%p,%p,%d)\n",file, buffer, length);
#endif
	message_ptr = buff;
	if(message_ptr == 0)
		return 0;

	while(length && *message_ptr)
	{

		put_user(*(message_ptr++), buffer++);
		length--;
		byte_read++;

	}
#ifdef DEBUG
	printk(KERN_INFO "read %d bytes , %d left \n",byte_read, length);
#endif

	return byte_read;
}

static ssize_t device_write(struct file *file, const char __user * buffer, size_t length, loff_t *offset)
{
	int i;
#ifdef DEBUG
	printk(KERN_INFO "device_write(%p,%s,%d)",file, buffer, length);
#endif

	for(i=0; i < length && i < BUF_LEN; i++)
		get_user(message[i], buffer+i);

	message_ptr = message;
	
return i;

}

int device_ioctl(struct inode *inode, struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{

	int i;
	char *temp;
	char ch;
       printk(KERN_INFO "*file:%p\r\n",file);

	switch(ioctl_num)
	{
		case IOCTL_SET_MSG:
			printk(KERN_INFO "ioctl_param in IOCTL_SET_MSG:%lu\r\n",ioctl_param);
			temp = (char *)ioctl_param;
			get_user(ch, temp);
			for(i=0; ch && i < BUF_LEN; i++, temp++)
				get_user(ch, temp);

			printk(KERN_INFO "i--->%d\r\n",i);
			device_write(file, (char *)ioctl_param, i, 0);
			break;

		case IOCTL_GET_MSG:

			printk(KERN_INFO "ioctl_param in IOCTL_GET_MSG :%lu\r\n",ioctl_param);
			i = device_read(file, (char *)ioctl_param, 99, 0);
			put_user('\0',(char *)ioctl_param+i);
			break;

		case IOCTL_GET_NTH_BYTE:
			printk(KERN_INFO "ioctl_param in IOCTL_GET_NTH_BYTE :%lu\r\n",ioctl_param);
			printk(KERN_INFO "message[ioctl_param]:%c\r\n",message[ioctl_param]);
			return message[ioctl_param];
			break;

	}

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

	ret_val = register_chrdev(MAJOR_NUM, DEVICE_NAME, &Fops);

	if(ret_val<0)
	{
		printk(KERN_INFO "%s failed with %d\n","sorry , registering the character device ", ret_val);

		return ret_val;
	}

	printk(KERN_INFO "%s the major device number is %d \n","registration  is a success ",MAJOR_NUM);
	printk(KERN_INFO " if u want to talk to the dvice driver,\n");
	printk(KERN_INFO "you 'll have to create a device file.\n");
	printk(KERN_INFO "we suggest you use:\n");
	printk(KERN_INFO "mknod %s c %d 0\n", DEVICE_FILE_NAME,MAJOR_NUM);
	printk(KERN_INFO "the device file name is important, because\n");
	printk(KERN_INFO "the ioctl program assumes that's the \n");
	printk(KERN_INFO "file you'll use.\n");

	return 0;

}


void cleanup_module()
{
	unregister_chrdev(MAJOR_NUM, DEVICE_NAME);

}

