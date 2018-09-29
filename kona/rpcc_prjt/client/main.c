#include <stdio.h>
#include<fcntl.h>
#include<errno.h>
#include "afop.h"
main()
{
	client_req();
	int fd,fd1,l=10,r,w,p,fa,la;
	char buf[100];
	fd=aopen("t.txt",O_RDONLY,0);
	printf("---->fd value is :%d\n",fd);
	fd1=aopen("new.txt",O_RDWR|O_CREAT,0644);
	printf("---->fd1 value is :%d",fd1);

	while(1)
	{
		r=aread(fd,buf,l);
		buf[r]='\0';
		printf("%s\n",buf);
		w=awrite(fd1,buf,r);
		if(r < l)
		{
			break;
		}
	} 
	p=add(10,20);
	printf("p val is :%d\n",p);
	fa=fact(5);
	printf("--->fa val is :%d\n",fa);
	la=addafter(10);
	printf("---->la val is :%d\n",la);
	aclose(fd);
	aclose(fd1);
}
