#include "fcntl.h"
int rpcc_fop(int i,int f,char *b,int l,char *p,int m,int fl,int y)
{
int fd,r,w,ls,t;
	switch (i)
	{	case 1:
				fd=open(p,m,fl);
				return fd;
				break;
		case 2:
		   		r=read(f,b,l);
				return r;
				break;
		case 3:
				w=write(f,b,l);
				return w;
				break;
		case 4:
				ls=lseek(f,l,y);
				return ls;
				break;
		case 5:
				t=close(f);
				return t;
				break;
		default:
				break;
	}
}
