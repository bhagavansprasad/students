#include "linux/config.h"
#include "linux/module.h"
#include "linux/unistd.h"
#include "linux/init.h"
#include "linux/fs.h"
#include "asm/uaccess.h"
#include "linux/slab.h"
#include "linux/list.h"

MODULE_LICENSE("GPL");

static int major;

struct RKS{
    struct list_head list;
    char name[30];
};

struct list_head rks_list;

static char *name[] = { "Ramprasad", "praneeth", "kushmita", "yvvrp", '\0' };

int rk_open(struct inode *inode, struct file *filp)
{
    return 0;
}

int rk_close(struct inode *inode, struct file *file)
{
    return 0;
}

ssize_t rk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    struct list_head *ptr;
    struct RKS *rksptr;

    printk("&rks_list      :%8p\r\n",&rks_list);
    printk("rks_list->next :%8p\r\n",rks_list.next);
    printk("rks_list->prev :%8p\r\n",rks_list.prev);

    for(ptr = rks_list.next; ptr != &rks_list; ptr = ptr->next)
    {
	rksptr = list_entry(ptr, struct RKS, list);
	printk("address of struct RKS :%8p\r\n", rksptr);
	printk("rks_list.next         :%8p\r\n", (*rksptr).list.next);
	printk("rks_list->prev        :%8p\r\n", (*rksptr).list.prev);
    }

    return 0;
}



struct file_operations rk_fops = {
open:	rk_open,
	release:rk_close,
	read:	rk_read,
	owner:	THIS_MODULE,
};

int init_module(void)
{
    int i;
    struct RKS *rksptr;
    major = register_chrdev(0,"rkdevice",&rk_fops);
    if( major < 0)
    {
	printk("Error in registering driver\n");
	return -1;
    }

    printk("Successfully registered rkdevice . Major = %d\n",major);
    printk("&rks_list = %8p\n",&rks_list);

    INIT_LIST_HEAD(&rks_list);
    for(i=0; i<4; ++i)
    {
	rksptr = kmalloc(sizeof(struct RKS), GFP_KERNEL);
	strcpy(rksptr->name, name[0]);
	list_add_tail(&(rksptr->list), &rks_list);
    }
    return 0;
}

void cleanup_module(void)
{
    int ret;
    struct list_head *ptr;
    struct RKS *rksptr;

    for(ptr = rks_list.next; ptr != &rks_list; ptr = ptr->next)
    {
	rksptr = list_entry(ptr, struct RKS, list);
	kfree(rksptr);
    }

    ret = unregister_chrdev(major, "rkdevice");
    if(ret < 0)
	printk("Error unloading rkdevice\n");
    else
	printk("unloading module rkdevice\r\n");

}


