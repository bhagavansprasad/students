#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "commondefs.h"
#include "structure1.h"
int rpcc_fop(struct u *uss)
{
	int df,i;
	if(uss->y==open_req)
	{
			df = open(uss->us.sopen.pathname,uss->us.sopen.flags,uss->us.sopen.mode);
			return df;
	}
	if(uss->y==read_req)
	{
			df = read(uss->us.sread.fd,uss->us.sread.buf,uss->us.sread.count);
			return df;
	}
	if(uss->y==write_req)
	{
			df=write(uss->us.swrite.fd,uss->us.swrite.buf,uss->us.swrite.count);
			return df;
	}
	if(uss->y==lseek_req)
	{
			df = lseek(uss->us.slseek.fd,uss->us.slseek.offset,uss->us.slseek.whence);
			return df;
	}
	if(uss->y==close_req)
	{
			df = close(uss->us.sclose.fd);
			return df;
	}
	return 0;
}
