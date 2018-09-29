#ifndef CHARDEV_H
#define CHARDEV_H
#include "linux/ioctl.h"
#define  MAJOR_NUM 1000
#define IOCTL_SET_MSG _IOR(MAJOR_NUM,0,char*)
#define IOCTL_GET_MSG _IOR(MAJOR_NUM,1,char*)
#define IOCTL_GET_NTH_BYTE _IOWR(MAJOR_NUM,2,int)
#define DEVICE_FILE_NAME "device_list"
#define CMD_ADD_ATBEG  104
#define CMD_ADDAFTER  105
#define CMD_IFLOOPREPEAT 106
#define CMD_DISPLAY 107
#endif




typedef struct node
{
        int val;
        struct node *next;
} node;
