#include<stdio.h>
#include<fcntl.h>
//#include<sys\types.h>
//#include<sys\stat.h>
#include<stdlib.h>
#include<unistd.h>
//int close int(fd);
int main()
{
char buff[178];
int fd,i;
fd=open("t.txt",O_RDONLY);

//for(i=0;buff[i]!='\0';i++)
//{
read(fd,buff,177);
buff[177]='/0';
printf("%s\n",buff);
//}
close(fd);
}
