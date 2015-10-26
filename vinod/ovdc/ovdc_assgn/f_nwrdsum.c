#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#define N 120

int count=0;
char str[10];
char str1[10];

void get_word(char *, int );

int main()
{
	unsigned char buff[101];
	int fc=0, retval=0;
	int a=0,b=0,c=0;
	int fd = open("myown.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		exit(0);
	}
	while(1)
	{
		retval = read(fd,buff,100);
		if(retval < 0)
		{
			perror("Error in reading file : ");
			exit(0);
		}
		buff[100]='\0';
		get_word(buff,N);
		if(count == N+1)
			break;
	}
	printf("%s\n",str);
	printf("%s\n",str1);
	sscanf(str,"%X",&a);
	sscanf(str1,"%X",&b);
	c = a+b;
	printf("The sum value is -> %X\n", c);
	if(close(fd)<0)
		perror("fail to close the file:");
	printf("\n");
	return 0;
}

void get_word(char *a, int n)
{
	int i,j=0;

	for(i = 0; a[i] !='\0'; i++)
	{
		if(a[i] != ' ' && i!=99)
		{
			count++;
			if(count == n)
			{
				for(j=0; a[i] != ' ' ; i++,j++)
					str[j] = a[i];
				str[j]='\0';
				continue;
			}
			if(count == n+1)
			{
				for(j=0; a[i] != ' ' ; i++,j++)
					str1[j] = a[i];
				str1[j]='\0';
				return;
			}
			for( ; a[i+1] !=' ' && a[i+1] != '\0'; i++);
		}
	}
}
