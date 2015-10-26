#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */

int init_module(void)
{
	printk("Hello world 1.tihs is my kernel module 1\n");
	return 0;
}

void cleanup_module(void)
{
	printk("Goodbye world 1 my kernel module 1 .\n");	
}
