#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	char a[10];
	int d;
	int l;
	l=open("a.txt",O_RDONLY);
	if(l==-1)
	{
		printf("file can not  be openend");
	}
	else
	{
		d=read(l,a,sizeof(a));
		printf("%d",d);
		a[d]='\0';
		printf("%s",a);
	}
	return 0;
}
