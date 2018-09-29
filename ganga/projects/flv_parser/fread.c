#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "stdbool.h"
#include "defs.h"

int main()
{
	int fd = 0;

	fd = open("sixth.flv", O_RDONLY, 0744);
	printf(" fd value is :%d\n", fd);

	flv_header(fd);
	flv_body(fd);

	return 0;
}

int flv_header(int fd)
{
	int n = 0, i = 0, retval = 0; 
	char buff[100];
	struct flv_header hdata; 
	char *cp = &hdata.data_offset;

	retval = read(fd, buff, 9);
	printf("\n-->flv header :\n read retval is :%d\n", retval);

	strncpy(hdata.sign, buff, 3);
	printf(" sign is :%s\n", hdata.sign);

	hdata.version = buff[3];
	printf("version is :%d\n", hdata.version);

	hdata.vedio_bit = (buff[4] & 1);
	printf(" vedio bit is :%d\n", hdata.vedio_bit);

	hdata.audio_bit = ((buff[4] >> 2) & 1);
	printf(" audio bit is :%d\n", hdata.audio_bit);

	for (i = 8 ; i >= 5 ; i--)
	{
		*cp = buff[i];
		cp++;
	}
	printf(" data offset is :%u\n", hdata.data_offset);

	return 0;
}

int flv_body(int fd)
{
	int  i = 0, retval = 0; 
	char buff[10];
	struct flv_body bdata; 
	char *cp = &bdata.previoustag;

	retval = read(fd, buff, 4);
	printf("\n-->flv body :\n read retval is :%d\n", retval);

	for (i = 0 ; i < 4 ; i++)
	{
		printf("previous tag is %d \n", bdata.previoustag);
	}

	flv_tags(fd);

	return 0;
}

int flv_tags(int fd)
{
	int a = 0, n = 0, retval = 0, mask = 0x1F; 
	char buff[10];
	struct flv_tags tdata; 

	retval = read(fd, buff, 7);
	printf("\n-->flv tags :\n read retval is :%d\n", retval);

	a = buff[0];
	n = ((a >> 6) & 3);
	printf("reserved tag is %d \n", n);

	n = ((a >> 5) & 1);
	printf("filter tag is %d \n", n);

	if (n == 0)
		printf("no processing required \n");
	else
		printf("pre-processing \n");


	n = a & mask;

	if(n = 8)
		printf("tag type is audio \n");

	if(n = 9)
		printf("tag type is vedio \n");

	if(n = 18)
		printf("tag type is script data \n");
	
/*	   tdata.datasize = buff[3];
	   printf("datasize tag is %d \n", tdata.datasize);

	   tdata.timestamp = buff[7];
	   printf("time stamp tag is %d \n", tdata.timestamp);
	 
*/	return 0;
}
