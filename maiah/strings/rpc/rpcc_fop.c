#include "stdio.h"
#include <fcntl.h>
#include "rpcc1.h"
int rpcc_fop(int i, struct open *ope, struct read *rd, struct write *wrt,struct lseek *lsk, struct close *cls)
{
	int fd,r,w,ls,t;
	switch (i)
	{	
		case 1:
			fd=open(ope->fname , ope->mode , ope->flag);
			return fd;

		case 2:
			r=read(rd->fd,rd->buff,rd->len);
			rd->buff[r]='\0';
			printf("final buff is: %s\n",rd->buff);
			return r;
		case 3:
			w=write(wrt->fd, wrt->buff, wrt->len);
			return w;
		case 4:
			ls=lseek(lsk->fd, lsk->len,lsk->whence);
			printf("-->length :%d\n",(int)lsk->len);
			printf("-->y :%d\n",lsk->whence);
			return ls;
		case 5:
			t=close(cls->fd);
			return t;
		default:
			printf("there are no elements:");

	}
}
