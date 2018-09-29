#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	char buf[500];
	int r,fd,i,j=0;
	fd=open("a.txt",O_RDONLY);
	while(1)
	{
		r=read(fd,buf,100);
		{
			for(;buf[i]==' ';)
				j++;
		}
	}
	j=j+1;
	printf("%d",j);
}
