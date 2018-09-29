#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

main()
{
int fd1,i,val,w=1;
char buff[100];
fd1=open("count.txt",O_RDONLY);
if(fd1==-1)
{
perror("file is not opened\n");
}
while(1)
{
val= read(fd1,buff,70);
buff[val]='\0';
printf("%s",buff);
for(i=0;buff[i]!='\0';i++)
{
if(buff[i]==' ')
{
w++;
}
}
printf("=======%d\n",w);
if(val<70)
{
break;
}
}
}
