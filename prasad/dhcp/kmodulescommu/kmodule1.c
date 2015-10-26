#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/init.h"

void fun1()
{
    printk("hai im in the kernelmodule1\r\n");
}

EXPORT_SYMBOL(fun1);

int init_module(void)
{
    printk("hello this kernelmodule 1\r\n");
    return 0;
}

void cleanup_module(void)
{
    printk("good bye kernelmodule 1 \r\n");
}

