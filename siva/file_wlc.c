#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<string.h>

main()
{
	int fd,val,n;
	char buff[255];
	fd=open("s.txt",O_RDONLY);
	if(fd==-1)
	{
		perror("file is not opened\n");
	}
	while(1)
	{
		val=read(fd,buff,30);
		printf("%d",val);
		buff[val]='\0';
		printf("%s",buff);
                n=no_char(&buff);

		if(val<30)
        {		 printf("number of characters%d\n",n);

			break;
		}
	}
}
no_char(char *buff)
{  int i;int ch=0;
	for(i=0;buff[i]!='\0';i++)
	{
		ch++;
	}
	return ch;
}

