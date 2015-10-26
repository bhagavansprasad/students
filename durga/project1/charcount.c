#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,r,len=10,i,n=1,s=0;
char buf[100];
fd=open("sample.txt", O_RDONLY)
for(i=o;i<n;i++)
{
  r=read(fd,buf,len);
  s+=r;
  if(r<len)
  i=i+n
  n++;
  }
  printf("%d",s);
  }

