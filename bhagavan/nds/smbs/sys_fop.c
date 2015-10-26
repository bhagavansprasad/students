#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "nds_smb_api.h"
#include "stdlib.h"

int sum=0;
int count =0;

int sys_open(client_request *creq, client_request *reply)
{
	int fd;

	memset(reply, 0, sizeof(client_request));

	strcpy(reply->file_name, creq->file_name);
	strcpy(reply->file_path, creq->file_path);
	reply->cmd = OPEN_REPLY;

	printf("-->smbS: Opening file :%s in mode :%x\n", creq->file_name, creq->mode);

	if((fd = open(creq->file_name, creq->mode, 0644)) == -1)
	{
		reply->ret_errno = errno;
		perror("-->smbS: error in open file");
		printf("-->smbS: *** ERROR IN OPENING *** file :%s in mode :%x, fd:%d\n",
				creq->file_name, creq->mode, fd);
	}
	else
		printf("-->smbS: *** SUCCESS IN OPENING *** file :%s in mode :%x\n", creq->file_name, creq->mode);

	reply->retval = fd;
	reply->offset = 0;

	if (fd >= 0)
		close(fd);

	return fd;
}

int sys_read(client_request *creq, char *out_buff)
{
	int fd;
	int retval;
	client_request *reply;

#if 0
	printf("%d\n", creq->cmd);
	printf("%s\n", creq->file_name);
	printf("%s\n", creq->file_path);
	printf("%d\n", creq->mode);
	printf("%d\n", creq->offset);
	printf("%d\n", creq->len);
	printf("%d\n", creq->ret_errno);
	printf("%d\n", creq->retval);
#endif

	memset(out_buff, 0, sizeof(client_request) + creq->len);

	reply = (client_request *)out_buff;

	strcpy(reply->file_name, creq->file_name);
	strcpy(reply->file_path, creq->file_path);
	reply->cmd = READ_REPLY;

	printf("-->smbS: Opening file :%s in mode :%x\n", creq->file_name, creq->mode);

	if((fd = open(creq->file_name, creq->mode, 0644)) == -1)
	{
		reply->ret_errno = errno;
		perror("-->smbS: error in open file");
		printf("-->smbS: *** ERROR IN OPENING *** file :%s in mode :%x, fd:%d\n",
				creq->file_name, creq->mode, fd);
		reply->retval = fd;
		reply->offset = 0;

		return fd;
	}

	lseek(fd, creq->offset, creq->whence); 

	reply->retval = retval = read(fd, out_buff+sizeof(client_request), creq->len);
	printf("smbS: Reading %d bytes from file\n", retval);
	reply->offset = lseek(fd, 0, SEEK_CUR); 
	printf("smbS: Current offset is  %d\n", reply->offset);

	close(fd);

	return retval;
}	

#if 0
int sys_write(int fd, char *rbuff, int len)
{
	int retval;

	if ((retval = write(fd, rbuff, len)) < 0)
		perror("Error in writing file");
	
	return retval; 
}	


int sys_close(int fd)
{
	int retval;

	if ((retval = close(fd)) < 0)
		perror("Error in closing file");

	return retval;
}
#endif
