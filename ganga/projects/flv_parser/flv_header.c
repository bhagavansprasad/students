#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "string.h"
#include "defs.h"

int fd5, fd6, fd7, fd8;
int read_flv_header(int fd)
{
	int n = 0, i = 0, retval = 0; 
	int wretval = 0; 
	char buff[20]; 
	char *cp;

	fd5 = open("v.flv", O_APPEND | O_RDWR | O_CREAT, 0744);
	fd8 = open("a.flv", O_APPEND | O_RDWR | O_CREAT, 0744);
	fd6 = open("key.flv", O_APPEND |O_RDWR | O_CREAT, 0744);
	fd7 = open("inter.flv", O_APPEND |O_RDWR | O_CREAT, 0744);
	
	retval = read(fd, buff, 9);

	strncpy(hdata.sign, buff, 3);
	hdata.sign[3] = '\0';

	hdata.version = buff[3];
	hdata.res = buff[4];
	buff[4] = 1;

	hdata.vedio_bit = (hdata.res & 1);

	hdata.audio_bit = ((hdata.res >> 2) & 1);

	cp = (char *)&hdata.data_offset;

	for (i = 8 ; i >= 5 ; i--)
	{
		*cp = buff[i];
		cp++;
	}

	retval = read(fd5, buff, 9);
	printf(" retval header :%d\n", retval);

	wretval = write(fd5, buff, 9);
	wretval = write(fd6, buff, 9);
	wretval = write(fd7, buff, 9);
	wretval = write(fd8, buff, 9);

	return 0;
}
