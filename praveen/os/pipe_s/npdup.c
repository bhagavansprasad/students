#include <stdio.h>
#include <fcntl.h>
main()
{
	int i,rval;
	char buff[4] = {"hi","hw r u","wat dng","k bye"};
	char max[20];
	fd = open("sai",O_RDWR);
	rval = write(fd,buff[i],10);
	i++;
	printf("the rval is :%d\n",rval);
	read(fd1,max,10);
	printf("the max returnd is :%s\n",max);
}
