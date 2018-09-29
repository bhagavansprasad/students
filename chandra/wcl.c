#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	int i,c=0,w=0,l=0,f=1,fd=-1,len=10,ret;
	char buff[100];
	fd=open("wh.txt",O_RDONLY);
	while(1)
	{
		ret=read(fd,buff,len);
		c=c+ret;
		for(i=0;buff[i]!='\0';i++)
		{
			if(buff[i]==' ')
			{
				w++;
			}
			if(buff[i]!=' ')
			{
				f=1;
			}
			if(buff[i]=='\n')
			{
				l++;
			}
		}
		if(ret<len)
		{
			break;
		}
	}
	if(f==0)
	{
		w=0;
	}
	else
	{
		w++;
	}
	printf("%d %d %d",l,w,c);
}
