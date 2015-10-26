#include<stdio.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	char s[100];
	int t=0,l=10,fd,i;
	printf("argc:%d\n",argc);
	for(i=1;i<argc;i++)
	{
		fd=open(argv[i],0,O_RDONLY);
		printf("argv[%d]:%s\n",i,argv[i]);
		printf("fd:%d\n",fd);
		do
		{
			t=read(fd,s,l);
		//	printf("t:%d\n",t);
			s[t]='\0';	
			printf("%s",s);
		}while(t==10);
	} 
}  	

