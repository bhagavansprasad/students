#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int nthword(char *,int,char *);

main(int argc,char *argv[])
{
	int fd,nread,fd1,num=14;
	char buff[100],*word;
//	for(;;)
	{
		if((fd=open(argv[1],O_RDONLY))<0)
		{
			printf("%d\n",fd);
			return -1;
		}
		nread = read(fd,buff,100);
		buff[nread]='\0';
		fd1 = open("pstau.txt",O_RDWR|O_CREAT|O_APPEND,0666);
		write(fd1,buff,100);
		
		close(fd);
	//	close(fd1);
		
		nthword(buff,num,word);
		printf("%s\n\n",word);
	}
}
int nthword(char *buff,int num,char *word)
{
	int count=0,fd,nread;
	char i=0,mem[100];
#if 0
#endif
	for(;*buff!='\0';)
	{
		for(;*buff==' ';buff++);
		for(;*buff!=' ';buff++);
		count++;
		
		if(count==num)
		{   
			buff--;
			for(;*buff!=' ';buff--,i++);
			buff++;
		
		for(;*buff!=' ';)
			{
				*word++=*buff++;
			}
		
		*word='\0';
		
		word=word-i;
		
		printf("%s\n",word);
			return 0;
		}	
	}
}
