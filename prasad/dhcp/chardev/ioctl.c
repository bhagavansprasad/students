#include"chardev.h"
#include"stdlib.h"
#include"stdio.h"
#include"fcntl.h"
#include"unistd.h"
#include"sys/ioctl.h"

ioctl_set_msg(int file_desc, char *messgae)
{
	int ret_val;
	ret_val = ioctl(file_desc, IOCTL_SET_MSG, messgae);
	if(ret_val<0)
	{
		printf("ioctl_set_msg failed:%d\n",ret_val);
		exit(-1);
	}
	
	printf("set_msg message :%s \n",messgae);
}


ioctl_get_msg(int file_desc)
{
	int ret_val;
	char message[100];

	ret_val = ioctl(file_desc, IOCTL_GET_MSG, message);

	if(ret_val<0)
	{
		printf("ioctl_get_msg failed :%d\n",ret_val);
		exit(-1);
	}

	printf("get_msg message :%s \n",message);
}


ioctl_get_nth_byte(int file_desc)
{
	int i;
	char c;

	printf("get_nth_byte message:");

	i=0;

	do{
		c = ioctl(file_desc, IOCTL_GET_NTH_BYTE, i++);
                printf("c=%c\r\n",c);
		if(c<0)
		{
			printf("ioctl_get_nth_byte failed at the %d'th byte:\n",i);
			exit(-1);
		}

		putchar(c);
	}while(c != 0);

	putchar('\n');
}



main()
{
	int file_desc, ret_val;
	char *msg = "user process is writing to the kerlnel\n";
        printf("msg in process:%p\r\n",msg);
	file_desc = open(DEVICE_FILE_NAME, 0);
	printf("file_desc:%d\r\n",file_desc);
	if(file_desc<0)
	{
		printf("can't open deicev file:%s\n", DEVICE_FILE_NAME);
		exit(-1);
	}

	ioctl_get_nth_byte(file_desc);
	ioctl_get_msg(file_desc);
	ioctl_set_msg(file_desc, msg);

	close(file_desc);

}

