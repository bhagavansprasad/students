#include <stdio.h>
#include <fcntl.h>
main()
{
	int i,rval;
	char buff[4] = {"hello","fine","nthing","k bye"};
	char max1[20];
	fd1 = open("siri",O_RDWR);
	read(fd,max1,10);
	printf("the max1 returnd is :%d\n",max1);
	rval = write(fd1,buff[i],10);
	i++;
	//printf("the rval is :%d\n",rval);
	//read(fd,max,10);
	//printf("the max returnd is :%s\n",max);
}
