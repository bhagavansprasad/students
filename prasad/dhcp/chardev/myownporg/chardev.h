#include "linux/ioctl.h"

#define MAJOR_NUM 100
#define DEVICE_NAME    "char_dev"
#define DEVICE_FILE_NAME  "char_dev"
#define SUCCESS 0
#define BUF_LEN 100
#define IOCTL_SET_MSG _IOR(MAJOR_NUM, 0, char *)
#define IOCTL_GET_MSG _IOR(MAJOR_NUM, 1, char *)
