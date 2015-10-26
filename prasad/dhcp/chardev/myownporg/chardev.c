#include "chardev.h"
#include "linux/module.h"
#include "linux/kernel.h"
#include "asm/uaccess.h"
#include "linux/fs.h"

int device_ioctl(struct inode *inode,struct file *file,unsigned int ioctl_num,unsigned long ioctl_param)
{
    int i;
    char message[BUF_LEN];
    char buff[BUF_LEN] = "this is kernel written message to the user";
    char *temp = (char *)ioctl_param;

    if(IOCTL_SET_MSG == ioctl_num)
    {
	get_user(*message, temp);
	for(i=0; message[i] && i < BUF_LEN ; i++, message[i] = *(++temp))
	    get_user(message[i], temp);
	printk(KERN_INFO "msg received my the kernel:%s\r\n",message);
    }
    else
    {
	for(i=0; buff[i]!='\0'; i++, temp++)
	    put_user(buff[i], temp);
	put_user('\0',(char *)ioctl_param+i);
    }
    return SUCCESS;
}

struct file_operations fops = 
{
    .ioctl = device_ioctl,
};

int init_module()
{
    int retval;
    if((retval=register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops))<0)
    {
	printk(KERN_ALERT "register_chardev failed :%d\r\n",retval);
	return retval;
    }

    return SUCCESS;
}

void cleanup_module()
{
    unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
}

