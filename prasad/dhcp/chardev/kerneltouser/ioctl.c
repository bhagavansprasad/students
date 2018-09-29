#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "chardev.h"
#include "sys/ioctl.h"

int ioctl_get_msg(int file_desc)
{
char usermsg[100];
ioctl(file_desc,IOCTL_GET_MSG, usermsg);
printf("message written by kernel:%s\r\n",usermsg);
return SUCCESS;
}

int main()
{
int file_desc = open(DEVICE_FILE_NAME,0);
ioctl_get_msg(file_desc);
return SUCCESS;
}

