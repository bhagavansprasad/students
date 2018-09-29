#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "struct.h"
main()
{
	int rfd=1,r=1;
	data s;

	rfd=open("structure.db",O_RDONLY,0777);
	if(rfd<0)
	{
		printf("the rfd and errno are %d %d\n",rfd,errno);
		printf("the file is not open because:");
	}
	printf("the file open is success\n");

	r=read(rfd,&s,sizeof(data));
	if(r<0)
	{
		printf("the r and errno are %d %d\n",r,errno);
		printf("the file is not write because:");
	}
	printf("the file write is success\n");
}
