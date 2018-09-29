#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


 extern int foo(void);
int bla()
  {
       int ret = foo();
	   printk("%d\n",ret);
  }

