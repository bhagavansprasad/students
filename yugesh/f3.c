#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
	int get wc(char*ptr)
	int get lc(char*ptr)
main()
{
	int len=10,fd,a=0,b=0,s=0;
	char buff[415];
	int ret;
	fd=open("t.txt",O_RDONLY);
	while(1);
	{
		ret=read(fd,buff,len);
		s=s+ret;
		buff[ret]='\0';
		printf("%s",buff);
		a+=get wc(buff);
		b+=get lc(buff);
		if(ret<len)
			break;
	}
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",s);
	int get wc(char*ptr);
	{
		int i;
		int wc=0;
		for(i=0;ptr[i]!='\0';i++)
	}
	if((ptr[i]==' '//ptr[i]=='\n')&&ptr[i+1]!=' ')
	{
		wc=wc++;
return(wc);
}
int get lc(char*ptr);
	int i;
	{
int wc;
for(i=0;ptr[i]!='\0';i++)
{
	if(ptr[i]=='\n')
		wc=wc++;
		}
return(wc);
}
