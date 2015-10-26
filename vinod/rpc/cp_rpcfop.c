#include "rpcstructs.h"

int rpc_fop(aopen_data *popen, aread_data *pread, awrite_data *pwrite, alseek_data *plseek, aclose_data *pclose)
{

	int fds = 0 , fdr = 0, fdw = 0, offval = 0, retval = 0;

	if( popen != NULL ) 
	{
		fds = open(popen->filename, popen->flag, popen->mode);

		return fds;
	}

	if( pread != NULL )
	{
		fdr = read(pread->fdr, pread->buffr, pread->countr);
		return fdr;
	}

	if( pwrite != NULL )
	{
		fdw = write(pwrite->fdw, pwrite->buffw, pwrite->countw);
		return fdw;
	}

	if( plseek != NULL )
	{	
		offval = lseek(plseek->fds, plseek->offset, plseek->whence);
		return offval;
	}

	if( pclose != NULL )
	{
		retval = close( pclose->fdc);
		return retval;
	}
	
	return 0;
}
