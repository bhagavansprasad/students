#include "rpcstructs.h"

int rpc_fop(auds d);

int rpc_open(char *filename, int flag, int mode)
{
        auds d1;
		int fd = -1;

        strcpy(d1.aust.aopen.filename, filename);
        d1.aust.aopen.flag = flag;
        d1.aust.aopen.mode = mode;
		
        d1.status = 1;
        
		fd = rpccfop(d1);
		
        return fd;
}

int rpc_read(int fdr, char *buff, int count)
{
       	auds d2;
        int rdval = 0;

        d2.aust.aread.fdr = fdr;
        d2.aust.aread.buffr = buff;
        d2.aust.aread.countr = count;

        d2.status = 2;
		
        rdval = rpccfop(d2);

        return rdval;
}
int rpc_write(int fdw, char *buff, int count)
{
       	auds d3;
		int wrval = 0;

        d3.aust.awrite.fdw = fdw;
        d3.aust.awrite.buffw =  buff;
        d3.aust.awrite.countw = count;

        d3.status = 3;
	
        wrval = rpccfop(d3);

        return wrval;
}


int rpc_lseek(int fd, int offset, int whence)
{
       	auds d4;
        int offstval = 0;

        d4.aust.alseek.fds = fd;
        d4.aust.alseek.offset = offset;
        d4.aust.alseek.whence = whence;
		
        d4.status = 4;
		
        offstval = rpccfop(d4);

        return offstval;
}
int rpc_close(int fd)
{
       	auds d5;
        int retval = 0;

        d5.aust.aclose.fdc = fd;

        d5.status = 5;
	
        retval = rpccfop(d5);

        return retval;
}
