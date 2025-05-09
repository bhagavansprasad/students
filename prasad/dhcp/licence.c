#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/init.h"

#define DRIVER_AUTHOR "RAM PRASAD"
#define DRIVER_DESC "my first driver"

static int __init init_hello_4(void)
{
    printk(KERN_INFO"hello , world 4\n");
    return 0;
}

static void __exit cleanup_hello_4(void)
{
    printk(KERN_INFO"Goodbye , world4\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

MODULE_SUPPORTED_DEVICE("testdevice");

