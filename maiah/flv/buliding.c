#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "struct.h"
main()
{
	int wfd=1,w=1;
	data s={"venky",23,45};

	wfd=open("structure.db",O_CREAT|O_RDWR,0777);

	if(wfd<0)
	{
		printf("the wfd and errno =%d %d\n",wfd,errno);
		perror("the file is not open because:");
	}
	printf("creating file is success\n");
	
	w=write(wfd,&s,sizeof(data));

	if(w<0)
	{
		printf("the w and errno =%d %d\n",w,errno);
		perror("the write is failed because:");
	}
	printf("writing file is success\n");

	printf("total write size=%d bytes\n",w);

}
