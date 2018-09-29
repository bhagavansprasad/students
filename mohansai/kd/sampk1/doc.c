this is my first kernel file 


----------------------->
 create a file test1. c 
 
 #include <linux/kernel.h> 
#include <linux/module.h>

int init_module(void)
{
    printk("Hello, world\n");
    return 0;
}

void cleanup_module(void)
{
    printk("Goodbye\n");
}


save it



------------>

write a make file 

obj-m += test.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


and save it as Makefile


------------------>


now run the file like -->  make


sudo insmod test1.ko

dmesg 

sudo rmmod test1

dmesg


so that we can seee the message 




