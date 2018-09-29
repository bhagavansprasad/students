#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bhagavan");
MODULE_DESCRIPTION("Import module");

int factorial(int n);
int is_prime(int n);

static int __init import_init(void)
{
	int retval = 0;
    printk(KERN_INFO "Hello world from import module!\n");

	retval = factorial(5);
    printk(KERN_INFO "Fact value :%d\n", retval);

	retval = is_prime(5);
    printk(KERN_INFO "is_prime value :%d\n", retval);

    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit import_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module import module.\n");
}

module_init(import_init);
module_exit(import_cleanup);

