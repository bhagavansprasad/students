//#define __KERNEL__
//#define MODULE
//#define MODVERSIONS

//#include <linux/config.h>
//#include <linux/modversions.h>
#include <linux/module.h>
#include <linux/unistd.h>
//#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");

int rk_open(struct inode *, struct file *);
int rk_close(struct inode *, struct file *);
ssize_t rk_read(struct file *, char *, size_t , loff_t *);
int init_module(void);
void cleanup_module(void);



static int major;

struct RKS
{
	struct list_head list;
	char name[30];
};
struct list_head rks_list;
static char *name[]={ "mohan krisha", "siva krishna","muralikrishna","sudhir","suddep","paidi",'\0'};

struct file_operations rk_fops =
{
			open: rk_open,
			release: rk_close,
			read: rk_read,
};


int rk_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int rk_close(struct inode *inode, struct file *filp)
{
	return 0;
};

ssize_t rk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	struct list_head *ptr;
	struct RKS *rksPtr;

	printk("&rks_list = %08x\n",&rks_list);
	printk("rks_list->next = %08x\n",rks_list.next);
	printk("rks_list->prev = %08x\n",rks_list.prev);

	for(ptr = rks_list.next; ptr != &rks_list; ptr=ptr->next)
	{
		rksPtr = list_entry(ptr, struct RKS, list);
		printk("address of struct RKS = %08x\n",rksPtr);
		printk("address of struct RKS = %08x\n",(*rksPtr).list.next);
		printk("rks_list->prev = %08x\n",(*rksPtr).list.prev);
	}
	return 0;
}

int init_module(void)
{
	int i;
	struct RKS *rksPtr;

	major = register_chrdev(0,"rkDevice",&rk_fops);

	if(major<0)
	{
		printk("Error in registering driver\n");
		return -1;
	}
	else 
		printk("successfully registred rkDevice. Major = %d\n",major);
		printk("successfully registred rkDevice. Major = %d\n",major);

	INIT_LIST_HEAD(&rks_list);

	  
	for(i = 0; i<4 ; i++)
	{
		rksPtr = kmalloc(sizeof(struct RKS),GFP_KERNEL);
		strcpy(rksPtr->name,name[0]);
		list_add_tail(&(rksPtr->list),&rks_list);
	}
	return 0;
}

void cleanup_module(void)
{
	//int ret;
	struct list_head *ptr;
	struct RKS *rksPtr;

	for(ptr = rks_list.next; ptr != &rks_list; ptr = ptr->next);
	{
		rksPtr=list_entry(ptr,struct RKS,list);
		kfree(rksPtr);
	}
#if 0
	ret = unregister_chardev(major,"rkDevice");
	if( ret < 0)
		printk("Error unloading rkDevice\n");
	else
		printk("Unloading module rkDevice\n");
#endif
}


