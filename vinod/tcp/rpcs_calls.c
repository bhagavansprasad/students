#include "rpc_structs.h"
#include <stdlib.h>
//extern *buff;

void rpcs_open(asuds *preply, auds *d2)
{
	int fd = -1;
	int o_errno = 0;
	
	fd = open(d2->aust.aopen.filename, d2->aust.aopen.flag, d2->aust.aopen.mode);

	if(fd < 0)
	{
		o_errno = errno;
		perror("open error->");
	}

	preply->type = 1;
	preply->asust.rp_open.o_fd = fd;
	preply->asust.rp_open.o_errno = o_errno;
	
}

void rpcs_read(asuds *preply, auds *d2)
{
	int rdval = -1;
	int r_errno = 0;
	
	rdval = read(d2->aust.aread.fdr, d2->aust.aread.buffr, d2->aust.aread.countr);
	
	printf("rdval in rpcs_read -> %d\n", rdval);
	printf("buffer read -> %s\n", d2->aust.aread.buffr);
	
	if(rdval == -1)
	{
		r_errno = errno;
		perror("Error -> ");
	}

	preply->type = 2;
	strcpy(preply->asust.rp_read.buff, d2->aust.aread.buffr);
	preply->asust.rp_read.rdval = rdval;
	preply->asust.rp_read.r_errno = r_errno;

}

void rpcs_write(asuds *preply, auds *d2)
{
	int wrval;
	int w_errno = 0;
	
	printf("buffer write -> %s\n",d2->aust.awrite.buffw);
	
	wrval = write(d2->aust.awrite.fdw, d2->aust.awrite.buffw, d2->aust.awrite.countw);
	printf("wrval in rpcs_write : %d\n", wrval);

	if(wrval == -1)
	{
		w_errno = errno;
		perror("Error-> ");
	}

	preply->type = 3;
	preply->asust.rp_write.wrval = wrval;
	preply->asust.rp_write.w_errno = w_errno;
}

void rpcs_lseek(asuds *preply, auds *d2)
{
	int offstval = -1;
	int l_errno = 0;

	offstval = lseek(d2->aust.alseek.fds, d2->aust.alseek.offset, d2->aust.alseek.whence);

	if(offstval == -1)
	{	
		l_errno = errno;
		perror("lseek Eror ->");
	}

	preply->type = 4;
	preply->asust.rp_lseek.l_fd = offstval;
	preply->asust.rp_lseek.l_errno = l_errno;
}

void rpcs_close(asuds *preply, auds *d2)
{
	int retval = -1;
	int c_errno = 0;

	retval = close(d2->aust.aclose.fdc);
	
	if(retval == -1)
	{
		c_errno = errno;
		perror("close error ->");
	}

	preply->type = 5;
	preply->asust.rp_close.c_retval = retval;
	preply->asust.rp_close.c_errno = c_errno;

}

