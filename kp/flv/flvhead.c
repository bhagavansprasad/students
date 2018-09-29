#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include<math.h>
#include<stdlib.h>
#include "flvhead.h"
int showbit(char , int , int );
int byte_fun(unsigned char * , int );
main()
{
	flv_header head;
	unsigned char buff[128];
	int i,retval=0;
	int fd;
	
	fd = open("sixth.flv", O_RDONLY);
	if(fd == -1)
	{
		printf("failed to open");
		exit(0);
	}


	retval = read(fd, buff,sizeof(flv_header));
	if(retval == -1)
	{
	printf("read fail");
	exit(0);
	}

	for (i = 0; i < 3; i++)
	{
		head.sign[i]=buff[i];
		head.sign[3] = '\0';
	}
	if((buff[0] != 'F') && (buff[1] != 'L') && (buff[2] != 'V'))
	{
	printf("this is not flv file");
	exit(0);
	}
	head.version   = buff[i];
	i++;
	head.is_video  = showbit(buff[i], 0, 1);
	head.reserved2 = showbit(buff[i], 1, 1);
	head.is_audio  = showbit(buff[i], 2, 1);
	head.reserved1 = showbit(buff[i], 3, 4);
	printf("buff=%d",i);
	i++;
	head.offset = byte_fun(&buff[i] , 4);

	printf("type :%s\tversion :%d\taudiotag :%d\tvideotag :%d\theader size is %x\n",head.sign,head.version,head.is_audio,head.is_video,head.offset);



}
int showbit(char val, int bita, int nbit)
{
	int f_bit = 0;
	int j=0;
	int n = nbit + bita;
	for(j = bita; j < n; j++)
	{
		f_bit += val & (1<<j);
	}
	if(bita != 0)
		f_bit = f_bit >> bita;
	return f_bit;
}
int byte_fun(unsigned char *buffer, int k)
{
	int i=0,val=0,j=k;

	for(i=0; i<k; i++, j--)
	{
		val += buffer[i] << (8 *( j-1));
	}
	return val;

}
