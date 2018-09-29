#include "linux/module.h"
#include "linux/init.h"
#include "linux/kernel.h"
#include "linux/jiffies.h"

static int __init hi(void)
{
printk(KERN_INFO "Module m1 is being loaded\n");
printk("current jiffies:%lu\n",jiffies);
return 0;
}

static void __exit bye(void)
{
printk(KERN_INFO "module m1 being unloaded.\n");
}

module_init(hi);
module_exit(bye);

