#include<stdio.h>
#include<fcntl.h>
main()
{
	int a,b;
	char buf[200];
	a=aopen("tt.txt",O_RDONLY);
	b=aread(a,buf,100);
	buf[b]='\0'; 
	printf("the no of character is %d\n",b);
}
