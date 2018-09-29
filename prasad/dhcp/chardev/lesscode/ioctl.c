#include "chardev.h"
#include "stdio.h"
#include "sys/ioctl.h"
#include "fcntl.h"
#include "unistd.h"

void ioctl_set_msg(int file_desc, char *message)
{
    ioctl(file_desc, IOCTL_SET_MSG, message);
    printf("message set by user to the kernel:%s\r\n",message);     
}

int main(int argc, char *argv[])
{
    int file_desc = open(DEVICE_FILE_NAME, 0);
    ioctl_set_msg(file_desc, argv[1]);
    close(file_desc);       

    return SUCCESS;
}
