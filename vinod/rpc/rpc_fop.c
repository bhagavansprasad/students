#include <stdio.h>
#include "rpcstructs.h"

int rpc_fop(struct a_open *rpc_open, struct a_read *rpc_read, struct a_write
*rpc_write, struct a_lseek *rpc_lseek, struct a_close *rpc_close)

{

	int fds = 0 , fdr = 0, fdw = 0, offval = 0, retval = 0;

	if( rpc_open != NULL ) 
	{
		fds = open( rpc_open -> filename, rpc_open -> flag, rpc_open -> mode);
		return fds;
	}

	if( rpc_read != NULL )
	{
		fdr = read( rpc_read -> fdr, rpc_read -> buff_r, rpc_read -> count_r);
		return fdr;
	}

	if( rpc_write != NULL )
	{
		fdw = write( rpc_write -> fdw, rpc_write -> buff_w, rpc_write -> count_w);
		return fdw;
	}

	if( rpc_lseek != NULL )
	{	
		offval = lseek( rpc_lseek -> fds, rpc_lseek -> offset, rpc_lseek -> whence);
		return offval;
	}

	if( rpc_close != NULL )
	{
		retval = close( rpc_close -> fdc);
		return retval;
	}
	
	return 0;
}
