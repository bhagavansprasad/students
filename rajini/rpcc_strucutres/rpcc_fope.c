#include "fcntl.h"
#include "struct.h"

int rpcc_fop(int i,struct open_data *odata,struct read_data *rdata,struct write_data *wdata,struct lseek_data *sdata,struct close_data *cdata)

{
	int fd,r,w,f,e,offset,whence;
	switch(i)
	{

		case 1:

			fd=open( odata->p, odata->mode, odata->flags );
			return fd;
			break;

		case 2:

			r=read( rdata->fd, rdata->buff, rdata->len );
			return r;
			break;

		case 3:	

			w=write( wdata->fd, wdata->buff, wdata->len );

			return w;
			break;

		case 4:

			f=lseek( sdata->fd, sdata->offset, sdata->whence);

			return f;
			break;

		case 5:

			e=close(cdata->fd);
			return e;
			break;
		default:
			printf("there is no elements");
			break;


	}
}
