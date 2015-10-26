#include "linux/kernel.h"
#include "linux/module.h"

int init_module(void)
{
printk(KERN_INFO "hello , world -this is the kernel speaking \n");
return 0;
}

