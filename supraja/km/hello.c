#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */
int fact(int n)
{
	int i,rf=1;
	for(i=1;i<=n;i++)
		rf = rf*i;
	return (rf);
}
static int __init hello_start(void)
{
	int f;
	printk(KERN_INFO "Loading hello module...\n");
	printk(KERN_INFO "Hello world\n");
	printk(KERN_INFO "Hai world,u r amazing\n");
	f = fact(5);
	printk("factorial is : %d\n",f);
	return 0;
}

static void __exit hello_end(void)
{
	printk(KERN_INFO "Goodbye Mr.\n");
}

module_init(hello_start);
module_exit(hello_end);
