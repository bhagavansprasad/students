#include "rpcstructs.h"
#include "rpcscalls.h"
int rpcsfop(auds d2)
{
	int fds=0,fdr=0,fdw=0,offval=0,retval=0;

	switch(d2.status)
	{
		case 1: 
				fds = rpcs_open(d2);
				return fds;

		case 2: 
				fdr = rpcs_read(d2);
				return fdr;

		case 3: 
				fdw = rpcs_write(d2);
				return fdw;

		case 4: 
				offval = rpcs_lseek(d2);
				return offval;

		case 5: 
				retval = rpcs_close(d2);
				return retval;

		default: printf("No match in rpcsfop\n");
	}
	return -1;
}
