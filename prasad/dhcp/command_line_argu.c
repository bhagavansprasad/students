#include "linux/module.h"
#include "linux/moduleparam.h"
#include "linux/kernel.h"
#include "linux/init.h"
#include "linux/stat.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAM");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 8888;
static char *mystring = "aura";
static int myintarray[2] = {-2 ,-2};
static int arr_argc = 0;

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long ineteger");
//module_param_string(mystring, char *, 4, 0000);
MODULE_PARM_DESC(mystring,"A character string");
module_param_array(myintarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintarray,"An array of integers");

static int __init hello_5_init(void)
{
    int i;
    printk(KERN_INFO "hello, world 5\n===================\n");
    printk(KERN_INFO "myshort is a short integer:%d\n",myshort);
    printk(KERN_INFO "myint is an integer:%d\n",myint);
    printk(KERN_INFO "mylong is a long integer:%ld\n",mylong);
    printk(KERN_INFO "mystring  is a string:%s\n",mystring);

    for(i=0; i<(sizeof(myintarray)/sizeof(int)); i++)
    {
	printk(KERN_INFO"myintarray[%d]=%d\n",i,myintarray[i]);
    }

    printk(KERN_INFO "got %d arguments for myintarray.\n",arr_argc);
    return 0;
}

static void __exit hello_5_exit(void)
{
    printk(KERN_INFO "Good bye, world5\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);





















