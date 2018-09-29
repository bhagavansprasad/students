#include "linux/module.h"
#include "linux/init.h"
#include "linux/fs.h"
#include "linux/slab.h"
#include "asm/semaphore.h"
#include "linux/unistd.h"

MODULE_LICENSE("GPL");

static int major;

int init_module(void)
{
int i;
major = register_chrdev(0, "mydevice", &fops);
if(major
