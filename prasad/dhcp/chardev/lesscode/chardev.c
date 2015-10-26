#include "chardev.h"
#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/fs.h"
#include "asm/uaccess.h"

int device_ioctl(struct inode *inode, struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
    char *temp = (char*)ioctl_param;

	printk("Kernel: Message in kernel in ioctl  %s\n",temp);

    return SUCCESS;  
}

struct file_operations fops= 
{
    .ioctl=device_ioctl,
};

int init_module()
{
    int retval;

    if ((retval = register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops)) < 0)
	{
		printk(KERN_ALERT "registering the char device is failed with %d \r\n", retval);
		return retval;
    }

    return SUCCESS; 
}

void cleanup_module()
{
    unregister_chrdev(MAJOR_NUM, DEVICE_NAME);   
}
