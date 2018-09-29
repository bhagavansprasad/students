#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello_start(void)
{
	printk(KERN_INFO "loading hello welcome to kernel  module programming....\n");
	printk(KERN_INFO "KERNEL 1st program \n");
	return 0;
}

static int __exit hello_end(void)
{
	printk(	KERN_INFO "good programming mr.\n");
}

module_init(hello_start);
module_exit(hello_end);
