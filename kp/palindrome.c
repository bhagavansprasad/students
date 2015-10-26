#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,r,a;
char buf[200]
fd=open("t.txt",O_RDONLY);
while(1)
{
r=read(fd,buf,100);
if(r==0)
{
break;
}
a=get_palindrome(buf);
printf("no of palindrome word is:%d\n",a);
}
}
int get_palindrome(char*p)
{
int b;
