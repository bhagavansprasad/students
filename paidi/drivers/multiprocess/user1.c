#include "device1.h" 
#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/ioctl.h"
main()
{
	int file_desc,ret_val;
	char *msg = "Message passed by ioctl\n";
	file_desc = open("/dev/device_list", 0);
	if(file_desc<0)
	{
		printf(" cant open file %s\n",DEVICE_FILE_NAME);
		exit(-1);
	}

	while(1)
	{
		ioctl(file_desc, CMD_ADD_ATBEG, 50);
		sleep(2);	
		ioctl(file_desc, CMD_ADDAFTER, 40);
		sleep(2);	
		ioctl(file_desc, CMD_IFLOOPREPEAT, 30);
		sleep(2);	
		ioctl(file_desc, CMD_DISPLAY, 20);
		sleep(2);

	}
}
