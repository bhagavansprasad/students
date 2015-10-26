#include "fcntl.h"
int rpcc_fop(int,char *,int,int,char *,int ,int int ) 
{
	if(ope==1)
	{
		int fd;
		fd=open(p,mode,flag);
		return fd;
		else if(ope==2)
		{
			int r;
			r=read(fd,buff,len);
			return r;
			else if(ope==3)
			{
				int w;
				w=write(fd,buff,r);
				return w;
				else if(ope==4)
				{
					int f;
					f=lseek(fd,len,num);
					return f;
					else if(ope==5)
					{
						int e;
						e=close(fd);
						return e;
					}
				}
			}
		}
	}
}
