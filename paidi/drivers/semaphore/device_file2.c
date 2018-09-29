#include "linux/kernel.h"
#include "linux/module.h"
#include "linux/unistd.h"
#include "linux/init.h"
#include "linux/fs.h"
#include "linux/slab.h"
#include "linux/list.h"
#include "asm/uaccess.h"
#include "device2.h"

#define SUCCESS 0
#define DEVICE_NAME "char_dev"
#define BUF_LEN 100


static int Device_open=0;
static char Message[BUF_LEN];
static char *Message_ptr;
node *head=NULL;

static int device_open(struct inode *inode,struct file  *file)
{

    printk(KERN_INFO "device_open(%p)\n",file);
    return SUCCESS;
    if(Device_open)
        return -EBUSY;
    Device_open++;
    Message_ptr=Message;
    try_module_get(THIS_MODULE);
    return SUCCESS;
}
static int device_release(struct inode *inode,struct file *file)
{
    #ifdef DEBUG
	printk(KERN_INFO "device_release(%p,%p)\n",inode,file);
    #endif
	Device_open--;
    module_put(THIS_MODULE);
    return SUCCESS;
}
static ssize_t device_read(struct file *file,char __user *buffer,size_t    length,loff_t *offset)
{
    int bytes_read=0;
    printk(KERN_INFO"device_read(%p%p%p)\n",file,buffer,length);
    if(*Message_ptr==0)
        return 0;
    while(length && *Message_ptr)
    {
        put_user(*(Message_ptr++),buffer++);
        length--;
        bytes_read++;
    }
    printk(KERN_INFO"ready %d bytes ,%d left\n",bytes_read,length);
    return bytes_read;
}
static ssize_t device_write(struct file *file,const char __user *buffer,size_t length ,loff_t *offset)
{
    int i;
    printk(KERN_INFO "device_write(%p,%s %d)",file,buffer,length);
    for(i=0;i<length&&i<BUF_LEN;i++)
        get_user(Message[i],buffer+i);
    Message_ptr=Message;
    return i;
}


int add_node(int p)
{
    node *new,*temp =NULL;
    new= kmalloc(sizeof(node),GFP_KERNEL);
    new->val=p;
    new->next=NULL;
    if(head==NULL)
    {
        head=new;
        return 0;
    }
    temp=head;
    while((temp->next)!=NULL)
        temp=temp->next;
    temp->next=new;
    return;

    printk(KERN_INFO "I am in  add node  parameater :%d\n", p);
}
int delete_node(int p)
{
    printk("delete node 10 \n");
    node *temp=NULL,*old=NULL;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->val==p)
        {
            if(temp==head)
            {
                head=temp->next;
                kfree (temp);
                return;
            }
            else
            {
                old->next=temp->next;
                kfree (temp);

                return;
            }
        }
        else
        {
            old=temp;
            temp=temp->next;
        }
    }   
    printk("the element you want to delete is not available\n");
    printk(KERN_INFO "I am in new_fun2 parameater :%d\n", p);

}
void display()
{
	node *new=NULL,*temp=NULL;
	printk("this is disply fun\n");
	if(head==NULL)
	{
		printk("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printk("|%d|%d|--->",temp->val,temp->next);
		temp=temp->next;
	}
	printk("\n");
}


int device_ioctl(struct inode *inode,
                 struct file *file,
                 unsigned int ioctl_num,
                 unsigned long ioctl_param)
{
    int i;
    char *temp;
    char ch;

    printk(KERN_INFO "I am in device_ioctl function in kernel module ioctl_num :%d\n", ioctl_num);

    switch(ioctl_num)
    {
        case IOCTL_SET_MSG:
            temp=(char*)ioctl_param;
            get_user(ch,temp);
            for(i=0;ch&&i<BUF_LEN;i++,temp++)
                get_user(ch,temp);
            device_write(file,(char*)ioctl_param,i,0);
            break;
        case IOCTL_GET_MSG:
            i=device_read(file,(char*)ioctl_param,99,0);
            put_user('\0',(char*)ioctl_param+i);
            break;
        case IOCTL_GET_NTH_BYTE:
            return Message[ioctl_param];
            break;
        case CMD_ADD_NODE:
            add_node(ioctl_param);
            break;
        case CMD_DELETE_NODE:
            delete_node(ioctl_param);
            break;
		case CMD_DISPLAY:
			display(ioctl_param);
			break;	
    }
    return SUCCESS;
}

struct file_operations Fops={
    .read=device_read,
    .write=device_write,
    .ioctl=device_ioctl,
    .open=device_open,
    .release=device_release,
};
int init_module()
{
    int ret_val;
    ret_val=register_chrdev(MAJOR_NUM,DEVICE_NAME,&Fops);
    if(ret_val<0)
    {
        printk(KERN_ALERT "%s failed with %d\n","SORRY ,Registering thecharcterdevice ", ret_val);
    }
    printk(KERN_INFO "%s the major device number is %d\n","Registering is a success",MAJOR_NUM);
    printk(KERN_INFO "IFyou want talk to the device driver,\n");
    printk(KERN_INFO"you'll have to creat a device file\n");
    printk(KERN_INFO "We suggest you see\n");
    printk(KERN_INFO "mknod %s c %d 0\n",DEVICE_FILE_NAME,MAJOR_NUM);
    printk(KERN_INFO "the device file name is important ,because \n");
    printk(KERN_INFO"the ioctl program assumes that's the\n");
    printk(KERN_INFO "file you'll use\n");
    return 0;
}
void cleanup_module()
{
    printk(KERN_INFO "Exiting module char_dev\n");
    unregister_chrdev(MAJOR_NUM,DEVICE_NAME);
}
