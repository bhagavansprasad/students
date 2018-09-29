#include "stdio.h"
#include "fcntl.h"
#include "struct.h"

int rpcc_fop(int i, struct open *ope, struct read *rd, struct write *wrt,struct lseek *lsk, struct close *cls)
{
	int fd,r,w,l,t;
	switch (i)
	{	
		case 1:

			fd=open(ope->fname , ope->mode , ope->flag);
			return fd;
			break;

		default:

			printf("there are no elements:");
			break;


		case 2:

			r=read(rd->fd,rd->buff,rd->len);
			return r;
			break;

		case 3:

			w=write(wrt->fd, wrt->buff, wrt->len);
			return w;
			break;

		case 4:

			l=lseek(lsk->fd, lsk->k,lsk->whence);
			//printf("-->length :%d\n",len);
			//printf("-->y :%d\n",whence);
			return l;
			break;

		case 5:

			t=close(cls->fd);
			return t;
			break;

	}
}
