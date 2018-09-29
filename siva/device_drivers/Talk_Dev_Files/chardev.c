#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#include "chardev.h"
#define SUCCESS 0
#define DEVICE_NAME "chardev"
#define BUF_LEN 80

static int Device_Open = 0;
static char Message[BUF_LEN];
static char *Message_ptr;

static int device_open(struct inode *inode,struct file *file)
{
	printk("ENTERED   Device  OPEN :\n");
#ifdef DEBUG
	printk(KERN_INFO "device_open(%p) \n",file);
#endif
 	if(Device_Open)
		return -EBUSY;
	Device_Open++;
	Message_ptr = Message;
	try_module_get(THIS_MODULE);
	printk("RETURNED   Device  OPEN :\n");
	return SUCCESS;
}

static int device_release(struct inode *inode,struct file *file)
{
	printk("ENTERED DEVICE_RELEASE :\n");
#ifdef DEBUG
	printk(KERN_INFO "device_release(%p, %p) \n",inode,file);
#endif
	Device_Open--;
	module_put(THIS_MODULE);
	return SUCCESS;
}

static ssize_t device_read(struct file *file,char __user *buffer,size_t length,loff_t *offset)
{
	int bytes_read = 0;
	printk( KERN_INFO "Entered Device READ\n");
#ifdef DEBUG
	printk(KERN_INFO "device_release(%p, %p,%d) \n",file,buffer,length);
#endif

	if (*Message_ptr == 0) 
	return 0;

	while (length && *Message_ptr)  
	{
		put_user(*(Message_ptr++), buffer++);
		length--;
		bytes_read++;
	}
	printk( KERN_INFO "Returned Device READ\n");
#ifdef DEBUG
	printk(KERN_INFO "READ %d bytes %d, left\n",bytes_read,length);
#endif

	return bytes_read;

}

static ssize_t device_write(struct file *file,const char __user *buffer,size_t length,loff_t *offset)
{

	int i;
	printk("ENTERED DEVICE WRITE MODULE:\n");
#ifdef DEBUG
	printf(KERN_INFO "device_Write(%p,%s,%d)",file,buffer,length);
#endif
	for(i=0;i<length && i<BUF_LEN;i++)
	get_user(Message[i],buffer+i);
	Message_ptr = Message;
	printk("STRING IS %s :\n",Message_ptr);
	printk("RETURNED DEVICE WRITE_MODULE :\n");
	return i;
}

int device_ioctl(struct inode *inode,struct file *file,unsigned int ioctl_num,unsigned long ioctl_param)
{
	int i;
	char *temp;
	char ch;
	printk("Entered DEVICE_IOCTL MODULE :\n");
		printk("ENTERED IOCTL_SET_MSG CASE :\n");
		temp = (char*)ioctl_param;
		get_user(ch,temp);
		for(i= 0;ch && i < BUF_LEN;i++,temp++)
		get_user(ch,temp);
		device_write(file,(char *)ioctl_param,i,0);
		printk("STRING IS %s\n",temp);
		printk("Returned IOCTL_SET_MSG CASE :\n");

	switch(ioctl_num)
	{
	case IOCTL_SET_MSG:
		printk("ENTERED IOCTL_SET_MSG CASE :\n");
		temp = (char*)ioctl_param;
		get_user(ch,temp);
		for(i= 0;ch && i < BUF_LEN;i++,temp++)
		get_user(ch,temp);
		device_write(file,(char *)ioctl_param,i,0);
		printk("Returned IOCTL_SET_MSG CASE :\n");
		break;
	case IOCTL_GET_MSG:
		printk("ENTERED IOCTL_GET_MSG CASE :\n");
		i=device_read(file,(char *)ioctl_param,99,0);
		put_user('\0',(char *)ioctl_param+1);
		printk("RETURNED IOCTL_GET_MSG CASE :\n");
		break;
	case IOCTL_GET_NTH_BYTE:
		printk("Entered IOCTL_GET_NTH_BYTE CASE :\n");
		printk("RETURNED IOCTL_GET_NTH_MSG CASE :\n");
		return Message[ioctl_param];
		break;
	}
	printk("Returned DEVICE_IOCTL Module:\n");
	return SUCCESS;
}

static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.ioctl = device_ioctl,
	.open = device_open,
	.release = device_release
};

int init_module(void)
{
	int ret_val;
	printk(KERN_INFO "Entered INIT MODULE\n");
	ret_val = register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops);
	if(ret_val < 0)
	{
		printk(KERN_ALERT "%s failed with %d\n","sorry,Registering the character device ",ret_val);
		return ret_val;
	}

	printk(KERN_INFO "%s The major device number id %d.\n","Registration is a Sucess ",MAJOR_NUM);
	printk(KERN_INFO "If you want to talk to the device driver ,\n");
	printk(KERN_INFO "You'll have to create a device file .\n");
	printk(KERN_INFO "We suggest yyou use :\n");
	printk(KERN_INFO "Mknod %s c %d 0\n",DEVICE_FILE_NAME,MAJOR_NUM);
	printk(KERN_INFO "THE device file name is important, because \n");
	printk(KERN_INFO "The Ioctl Programm assumes that's the\n");
	printk(KERN_INFO "file you'll use.\n");
	printk("Returned INIT MODULE :\n");
	return 0;
}

void cleanup_module()
{
	printk(KERN_INFO "Entered Device CLEANUP_MODULE\n");
	unregister_chrdev(MAJOR_NUM,DEVICE_NAME);
	printk( KERN_INFO "RETURNED Device CLEANUP_MODULE\n");
}




