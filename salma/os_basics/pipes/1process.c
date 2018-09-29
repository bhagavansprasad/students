#include<stdio.h>
main()
{
int rval,sum=0,x=0,diff=0,var1,var2=0,y=0,len=10;
char buff[20];
int fd[]=open("/proc/5006/stat",O_RDONLY);
for(i=0;i<5;i++)
{
 while(1)
 {
   rval=read(fd,buff,len);
   buff[rval]='\0';
 }

}
}
