#include"linux/ioctl.h"

#define BUF_LEN 100
#define SUCCESS 0
#define MAJOR_NUM 100
#define IOCTL_SET_MSG _IOR(MAJOR_NUM, 0, char *)
#define DEVICE_FILE_NAME "char_dev"	
#define DEVICE_NAME "char_dev"
