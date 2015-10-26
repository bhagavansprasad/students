#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/ioctl.h"
#include "chardev.h"

int ioctl_set_msg(int file_desc, char *msg)
{
    ioctl(file_desc, IOCTL_SET_MSG, msg);
    printf("ths message passed to the kaernel is :%s\r\n",msg);
    return SUCCESS;
}

int ioctl_get_msg(int file_desc)
{
    char userbuff[BUF_LEN];
    ioctl(file_desc, IOCTL_GET_MSG, userbuff);
    printf("kernel written msg:%s\r\n",userbuff);
    return SUCCESS;
}

int main(int argc, char *argv[])
{
    int file_desc = open(DEVICE_FILE_NAME,0);
    if(file_desc<0)
    {
	printf("Device file is failed to open:%d\r\n",file_desc);
	exit(-1);
    }
    ioctl_set_msg(file_desc,argv[1]);
    ioctl_get_msg(file_desc);
    return SUCCESS;
}

