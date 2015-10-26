#include "fcntl.h"
int rpcc_fop(int i,int fd,char * buff,int len,char *p,int m,int flag,int y)
{
if(i==1)
   {
      int fd;
	  fd=open(p,m,flag);
	  return fd;
	}
else if(i==2)
   {
     int r;
	 r=read(fd,buff,len);
	 return r;
    }
else if(i==3)
   {
     int w;
	 w=write(fd,buff,len);
	 return w;
	}
else if (i==4)
    {
	  int f;
	  f=lseek(fd,len,y);
	  return f;
	 }
else if(i==5)
    {
	  int e;
	  e=close(fd);
	  return e;
	  }
}
