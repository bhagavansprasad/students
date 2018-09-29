#include "linux/module.h"
#include "linux/kernel.h"


void fun2()
{
    printk("hai im in the kernelmodule2\r\n");
}

EXPORT_SYMBOL(fun2);

int init_module(void)
{
    printk("hello this kernelmodule 2\r\n");
    return 0;
}

void cleanup_module(void)
{
    printk("good bye kernelmodule 2 \r\n");
}

