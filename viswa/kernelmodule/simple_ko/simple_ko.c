#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_LICENSE("AMRUTHALA");
MODULE_AUTHOR("VISWANATH");
MODULE_DESCRIPTION(" A SIMPLE HELLO WORLD WORLD MODULE");

static int __init hello__init(void)
{
	printk(KERN_INFO "hello world! \n");
	return 0;
}

static void __exit hello__exit(void)
{
	printk(KERN_INFO "EXIT and clean the module\n");
}

module_init(hello__init);
module_exit(hello__exit);
