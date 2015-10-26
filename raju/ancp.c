#include<stdio.h>
#include<fcntl.h>
main()
{
	char s[100];
	int r=0,w=0,l=20,i;
	int fd1=open("a.txt",0,O_RDONLY);
	int fd2=open("q.txt",O_CREAT | O_RDWR,0777);
	
	for(i=0;i<2;i++)
	{
	  r=read(fd1,s,l);
	  w=write(fd2,s,r);
	
	  lseek(fd1,-l,SEEK_END);

     }
	 close(fd1);
	 close(fd2);
}	 


