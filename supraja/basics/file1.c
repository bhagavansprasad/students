#include<stdio.h>
#include<fcntl.h>
int main()
{
	char buff[100];
	int fd,rval,s=0;
	fd=open("t.txt",O_RDONLY);
	while(1)
	{
		rval=read(fd,buff,10);
		buff[rval]='\0';
		printf("%s",buff);
		//s=s+rval;
		//printf("\n length is : %d",s);
		if(rval<10)
		//s=s+buff;
		//printf("\n length of string is :%d",s);
			break;
	}
	s=s+rval;
	printf("\n length is :%d",s);
	close(fd);
}
