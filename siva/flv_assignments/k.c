#include "flv_structures.h"
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int open_file()
{
	int fd;
	fd=open("sixth.flv",O_RDONLY);
	if(fd==-1)
	{
		perror("File is not opened\n");
		exit(0);
	}
	return fd;
}
int read_header(int fd,flv_header *phead)
{	
	int val=0;

	val = read(fd, phead->signature, 3);
	phead->signature[4]='\0';

	if((strncmp(phead->signature, "FLV", 3) != 0))
	{	
		printf("Invalid Signature :%s\n", phead->signature);
		exit(1);
	}
	printf("Signature :%s\n", phead->signature);

	val=read(fd, &phead->version, 1);
	if(phead->version == 1)
		printf("VERSION :%d\n",phead->version);
	else
		printf("VERSION NUMBER IS NOT MATCHED%d\n",phead->version);
	val=read(fd,&phead->flag,1);
	printf("FLAG =%d\n",phead->flag);
	if(phead->flag==5)
		position(5,0,2);
	else
		printf("FLAG IS NOT 5\n",phead->flag);
	val=read(fd,&phead->byte_off_set,4);
	printf("%d\n",val);	
	int i;
	i=swap_uint32(phead->byte_off_set);  //MACRO CALL
	printf("BYTE OFFSET=%d\n",i);
	return 0;

}


int main()
{
	int fd;
	flv_header header;
	fd=open_file();
	read_header(fd,&header);
	return 0;
}





