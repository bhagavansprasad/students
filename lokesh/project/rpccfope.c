#include "stdio.h"
#include "fcntl.h"
#include "rpccfop.h"

int rpcc_fope(struct loke *n)
{
switch(fope)
{
int k,r,w,t,f,offset,whence,rfd;

	case 1:
		k=open(odata->fname,odata->mode,odata->flags);
		printf("file name is : %s\n",odata->fname);
		printf("fd is : %d\n",k);
		return k;
		break;
	case 2:
		r=read(rdata->rfd,rdata->rbuff,rdata->len);
		printf("return fd : %d\n",r);
		printf(" --->%s\n",rdata->rbuff);
		return r;
		break;
	case 3:
		w=write(wdata->wfd,wdata->wbuff,wdata->len);
		return w;
		break;
	case 4:
		printf("-->in final offset : %d\n",offset);
		printf("-->in final whence : %d\n",whence);
		t=lseek(sdata->rfd,sdata->offset,sdata->whence);
		return t;
		break;
	case 5:
		f=close(cdata->fd);
		return f;
		break ;
		default:
		printf("there is no elements");
		break;
		}
		}

		
		
