#include<stdio.h>
#include<fcntl.h>

int main()
{
	char buff[100];
	int fd,rval,t,w=1,s=1;

	fd = open("t.txt", O_RDONLY);
	while(1)
	{
		rval=read(fd,buff,20);
		buff[rval]='\0';

		t=get_word_count(buff);

		printf(" %d ",t);
		s=s+t;

		if(rval<20)
			break;
	}
	printf(" \n num of words is : %d",s);

	close(fd);
}

int get_word_count(char *ptr)
{
	int i,w=0;

	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]==' ')
			w=w+1;
	}
	return (w);
}
