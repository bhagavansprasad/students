#include <stdio.h>
main()
{
	fd=open("t.txt",O_RDONLY);
	while(len>ret)
	{
		ret=read(fd,buff,len);
		sum=sum+ret;
		buff[ret]='\0';
		printf("%s",buff);
	}
}
