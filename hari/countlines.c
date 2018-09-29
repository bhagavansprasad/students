#include<stdio.h>
#include <fcntl.h>
main()
{
	int i,r,fd,count=0;
	
	char buf[100];
	
	fd=open("smpl.txt",O_RDONLY);
	
	r=read(fd, buf,100);
	
	buf[r]='\0';
	
	for(i=0;buf[i]!='\0';i++)
	{
		if(buf[i]=='\n')
		
		count++;
	}
	
	printf("%d",count);
}

