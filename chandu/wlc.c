#include<stdio.h>
#include<fcntl.h>
int word_count(char* buffer);
int get_linecount(char* a);

main() 
{
	char buffer[500];
	int retval=0,length=100,lcount=0,count=0;
	int fd;

	fd= open("r.txt",O_RDONLY);
	while(1)
	{
	    retval= read(fd,buffer,100);
		buffer[retval]='\0';
		count+=word_count(buffer);
        lcount+=get_linecount(buffer);

		printf("%s",buffer);

//	printf("wordcount:%d\n",count);
	
	
//	printf("linecount:%d\n",lcount);

		if (retval<length)
			break;
	}
	close(fd);

	printf("wordcount:%d\n",count);
	printf("linecount:%d\n",lcount);
}


int get_linecount(char*a)
{  
int i=0,count=0;
    for(i=0;a[i]!='\0';i++)
	{ 
	    if (a[i]=='\n')
		{ 
		   count++;
		}
	}
	return(count);
}
