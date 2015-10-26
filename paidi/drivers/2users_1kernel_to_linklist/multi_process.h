#ifndef CHARDEV_H
#define CHARDEV_H

#include "linux/ioctl.h"

#define  MAJOR_NUM 1000
#define IOCTL_SET_MSG _IOR(MAJOR_NUM,0,char*)
#define IOCTL_GET_MSG _IOR(MAJOR_NUM,1,char*)
#define IOCTL_GET_NTH_BYTE _IOWR(MAJOR_NUM,2,int)
#define DEVICE_FILE_NAME "chardev_ioctl"

#define CMD_ADD_NODE 100
#define CMD_ADD_NODE 101
#define CMD_ADD_NODE 102
#define CMD_ADD_NODE 103
#define CMD_ADD_NODE 104
#define CMD_DELETE_NODE 108

#endif

typedef struct node
{
	int val;
	struct node *next;
} node;

