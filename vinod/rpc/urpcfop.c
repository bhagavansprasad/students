#include "rpcstructs.h"

int rpc_fop(auds d)
{

        int fds = 0 , fdr = 0, fdw = 0, offval = 0, retval = 0;
		
		switch(d.status)
		{
			case 1:
					{
                		fds = open(d.aust.aopen.filename, d.aust.aopen.flag, d.aust.aopen.mode);
                		return fds;
        			}

        	case 2:
					{
                		fdr = read(d.aust.aread.fdr, d.aust.aread.buffr, d.aust.aread.countr);
                		return fdr;
        			}
		
        	case 3:
			       	{
            		   	fdw = write(d.aust.awrite.fdw, d.aust.awrite.buffw, d.aust.awrite.countw);
                		return fdw;
        			}

        	case 4:
					{
                		offval = lseek(d.aust.alseek.fds, d.aust.alseek.offset, d.aust.alseek.whence);
               			return offval;
       				}
		
        	case 5:
					{
                		retval = close( d.aust.aclose.fdc);
               			return retval;
       				}
			default:
					printf("status not matching\n");
		}

        return 0;
}
