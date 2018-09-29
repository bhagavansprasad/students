#include "linux/module.h"
#include "linux/init.h"
#include "linux/kernel.h"

static int myvar = 10;
int myvar2 = 20;
int myvar3 = 30;

EXPORT_SYMBOL(myvar3);



static int __init hi(void)
{
printk(KERN_INFO "Export module is loading\n");
return 0;
}

static void __exit bye(void)
{
printk(KERN_INFO "Export module is unloading\n");
}

module_init(hi);
module_exit(bye);


