#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int hello_start(void)
{
	printk(KERN_INFO "Loading hello module...\n");
	printk(KERN_INFO "Hello world\n");
	return 0;
}

static void hello_end(void)
{
	printk(KERN_INFO "Goodbye \n");
}

module_init(hello_start);
module_exit(hello_end);
