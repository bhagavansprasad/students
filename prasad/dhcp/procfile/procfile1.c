#include "linux/module.h"
#include "linux/kernel.h"
#include "linux/proc_fs.h"

#define PROCFS_NAME "helloworld"


struct proc_dir_entry *our_proc_file;


int procfile_read(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data)
{
    int ret;
    printk(KERN_INFO "procfile_read(/proc/%s) called \n", PROCFS_NAME);

    if(offset > 0)
    {
	ret=0;
    }
    else 
    {
	ret =  sprintf(buffer, "helloworld!\n");
    }
    return ret;
}

int init_module()
{
    our_proc_file = create_proc_entry(PROCFS_NAME, 0644, NULL);
    printk(KERN_INFO "/our_proc_file%x\n",our_proc_file);
    if(our_proc_file == NULL)
    {
	remove_proc_entry(PROCFS_NAME, &proc_root);
	printk(KERN_ALERT "error : could not initialize /proc/%s\n",PROCFS_NAME);
	return -ENOMEM;

    }

    our_proc_file->read_proc = procfile_read;
    our_proc_file->owner = THIS_MODULE;
    our_proc_file->mode = S_IFREG | S_IRUGO;
    our_proc_file->uid = 0;
    our_proc_file->gid = 0;
    our_proc_file->size = 37;

    printk(KERN_INFO "/proc/%s created\n",PROCFS_NAME);
    return 0;
}


void cleanup_module()
{
    remove_proc_entry(PROCFS_NAME, &proc_root);
    printk(KERN_INFO "/proc/%s removeed\n",PROCFS_NAME);
}



