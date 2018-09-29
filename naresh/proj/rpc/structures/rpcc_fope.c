#include "fcntl.h"
#include "rpcc_fope.h"
#include "string.h"
#include "struct.h"

int rpcc_fope(int ope,struct open *op,struct read *pr,struct write *pw,struct lseek *pseek,struct close *pcls)
{
	int fd,r,w,l,t;
	switch(ope)
	{
	case 1:
		int fd;
		fd = open(op->fname, op->mode, op->flag);
		return fd;
	case 2:
		int r;
		r = read(pr->fd, pr->buff,pr->len);
		return r;
	case 3:
		int w;
		w = write(pw->fd, pw->buff, pw->len);
		return w;
	case 4:	
		off_t l;
		l = lseek(pseek->fd, pseek->len, pseek->whence);
		return l;
	case 5:
		int t;
		t = close(pcls->fd);
		return t;
	default:
		printf("no valid file\n");
}
