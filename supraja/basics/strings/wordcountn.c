#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    char buff[100];
	int fd,rval,wc=1,t;
	fd=open("t.txt",O_RDONLY);
	if(fd<0)
	{
		printf("there exist error in opening file");
		exit(1);
	}
	while(1)
	{
		rval=read(fd,buff,13);
		buff[rval]='\0';
		printf("%s",buff);
		t=get_words_count(buff);
		wc=wc+t;
		if(rval<10)
			break;
	}
	printf("the number of words in opened file is :%d \n",wc);
	close(fd);
	return (0);
}
int get_words_count(char *ptr)
{
	int i,w=0;
	for(i=0;ptr[i]!='\0';i++)
	{
	    if(ptr[0]==' ')
		   continue;
		if(ptr[i]==' '&&ptr[i+1]==' ')
			continue;
			//if(ptr[i]=='\0')
			//continue;
		if(ptr[i]=='\n'&&ptr[i+1]==' ')
		    continue;
		if(ptr[i]==' ')
			w=w+1;
		if(ptr[i]=='\n')
			w=w+1;
	}
	return (w);
}
