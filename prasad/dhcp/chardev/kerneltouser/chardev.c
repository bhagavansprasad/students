#include "chardev.h"
#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/fs.h"
#include "asm/uaccess.h"

int device_ioctl(struct inode *inode, struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
char buff[]="this is kernel writing message to the userprocessohhgihgihg";
int i;
char *msg_ptr = (char *)ioctl_param;
for(i=0; buff[i] != '\0';  i++)
put_user(buff[i], msg_ptr++);
put_user('\0',(char *)ioctl_param+i);

return SUCCESS;

}

struct file_operations fops=
{
.ioctl = device_ioctl,
};

int init_module()
{
int retval;
if(retval=(register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops))<0)
{
printk(KERN_ALERT "registering char dev failed:%d\r\n",retval);
return retval;
}
return SUCCESS;
}

void cleanup_module()
{
unregister_chrdev(MAJOR_NUM,DEVICE_NAME);
}

