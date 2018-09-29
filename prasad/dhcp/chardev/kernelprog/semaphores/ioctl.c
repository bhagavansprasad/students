#include"stdlib.h"
#include"stdio.h"
#include"fcntl.h"
#include"unistd.h"
#include"sys/ioctl.h"

main()
{
	int file_desc, ret_val;
	char *msg = "user process is writing to the kerlnel\n";
        printf("msg in process:%p\r\n",msg);
	file_desc = open("rkdevice", 0);
	printf("file_desc:%d\r\n",file_desc);
	if(file_desc<0)
	{
		printf("can't open deicev file because semlocked:%s\n","rkdevice");
		exit(-1);
	}

//	ioctl_get_msg(file_desc);
//	ioctl_set_msg(file_desc, msg);

	close(file_desc);

}


