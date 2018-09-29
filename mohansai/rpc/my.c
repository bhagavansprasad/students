#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "mydefs.h"
#include "nds_smb_api.h"
#include "string.h"

int main(int argc ,char *argv[])
{
	int fd,fs;
	int retval = 0, wretval=0;
	char buff[1024];

	if(argc < 2)
	{
		printf("In sufficient arguments in input\r\n");
		exit(1);
	}

	fd = nds_smb_open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("File open failed");
		exit(1);
	}

	fs = nds_smb_open(argv[2], O_CREAT|O_RDWR);

	if(fd==-1)
	{
		printf("file open failed");
		exit(1);
	}

	while(1)
	{
		retval = nds_smb_read(fd, buff, READ_SIZE);
		
		buff[retval] = '\0';

		if(retval < 0)
		{
			printf("Read failed\r\n");
			break;
		}

		wretval = nds_smb_write(fs, buff, retval);
	//	printf("buff %s",buff);

		if (retval != wretval)
		{
			printf("Write failed\r\n");
			break;
		}
		
	//	printf("Reading :%d bytes and wrote :%d bytes...\r\n", retval, wretval);

		if(retval < READ_SIZE)
			break;
	}	
	if (nds_smb_close(fd) < 0)
		printf("nds_smb_Close failed\r\n");

	if (nds_smb_close(fs) < 0)
		printf("nds_smb_Close failed\r\n");

	return 0;
}
