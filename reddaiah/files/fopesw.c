#include "fcntl.h"
int rpcc_fop(int i,int f,char *buff,int len,char *p,int m,int flag,int y)
{
   int fd,r,w,t,e;
   switch(i)
   {
     case 1:
	 fd=open(p,m,flag);
	 return fd;
	 case 2:
	 r=read(fd,buff,len);
	 return r;
	 case 3:
	 w=write(fd,buff,len);
	 return w;
	 case 4:
	 t=lseek(fd,len,y);
	 return t;
	 default:
	 e=close(fd);
	 return e;
	}
}
