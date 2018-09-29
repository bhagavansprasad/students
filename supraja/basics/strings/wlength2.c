#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	char buff[100];
	int fd,rval,s=0,l,wc=0,t,t1=0,l1;
	fd=open("t4.txt",O_RDONLY);
	while(1)
	{
		rval=read(fd,buff,10);
		buff[rval]='\0';
		printf("%s",buff);
		l=get_lines_count(buff);
		t=get_words_count(buff);
		s=s+rval;
		wc=wc+t;
		t1=t1+l;
		if(rval<10)
			break;
	}
	printf("%d \n",s);
	printf("%d \n",t1);
	printf("%d \n",wc);
	close(fd);
	return (0);
}
int get_lines_count(char*ptr)
{
	int i,l1=0;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]=='\n')
			l1++;
	}
	return (l1);
}
int get_words_count(char*ptr)
{
	int j,w=0;
	for(j=0;ptr[j]!='\0';j++)
	{
		if(ptr[j]==' ')
			w=w+1;
		if(ptr[j]=='\n')
			w=w+1;
	}
	return (w);
}
