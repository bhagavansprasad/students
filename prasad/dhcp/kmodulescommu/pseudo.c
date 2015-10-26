#include "pseudo.h"
#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/fs.h"
#include "asm/uaccess.h"

void fun1();
void fun2();

int retval;
int device_ioctl(struct inode *inode, struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
	char *temp = (char*)ioctl_param;

	printk("Kernel: Message in kernel in ioctl  %s\n",temp);

	switch(ioctl_num)
	{
		case FUN1:
			fun1();
			break;
		case FUN2:
			fun2();
			break;
	}

			return 0;  
			}
	struct file_operations fops= 
	{
		.ioctl=device_ioctl,
	};

	int init_module()
	{

		if ((retval = register_chrdev(0, DEVICE_NAME, &fops)) < 0)
		{
			printk(KERN_ALERT "registering the char device is failed with %d \r\n", retval);
			return retval;
		}
        printk(KERN_INFO,"major number:%d\r\n",retval);
		return 0; 
	}

	void cleanup_module()
	{
		unregister_chrdev(retval, DEVICE_NAME);   
	}

