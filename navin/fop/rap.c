#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

main()
{
int fd,i;

char buff[500];

fd=open("1.txt",O_RDONLY);
if(fd==-1)
printf("File not available \n");
else
{
i=read(fd,buff,30);
buff[i]='\0';
printf(" printing file 1.txt \n %s \n" ,buff);
printf(" total characters is %d \n",i);
}
}

