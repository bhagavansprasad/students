#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int astrlen(char *buff);
int getwordcount(char *buff);
int aline(char *buff);

main()
{
	int fd,i,len=0,count=0,line=0;
	char buff[100];
	fd=open("tetx.txt",O_RDONLY);
	while(1)
	{
		i=read(fd,buff,10);
		buff[i]='\0';
		if(i <= 0  )
		{
			printf("---------------------%s\n",buff);
			break;
		}
		printf("%s",buff);
		len+=astrlen(buff);
		count+=getwordcount(buff);
		line+=aline(buff);
	}
	printf("%d %d %d\n",line,count,len);
}

int astrlen(char *buff)
{
	int j=0;
	while(buff[j] != '\0')
	{
		j++;
	}
	return j;
} 
int getwordcount(char *buff)
{
	int k=0,l=0;
	while(buff[k]!= '\0')
	{
		if((buff[k] == ' ')&&(buff[k+1] != ' '))
		{
			l++;
		}
		k++;
	} 
	return l;
} 

int aline(char *buff)
{
	int m=0,n=0;
	while(buff[m] != '\0')
	{
		if(buff[m] == '\n')
		{
			n++;
		}
		m++;
	}
	return n;
}
