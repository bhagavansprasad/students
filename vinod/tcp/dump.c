#include <stdio.h>
#include "rpc_structs.h"
extern char *buffer;

void dump_call(st_dump d)
{
	switch(d.type)
	{
		case 1:
		printf("IN client side\n");
		switch(d.var.st_client->status)
				{
					case 1:	
							printf("--> Open <--\n");
							printf("file name : %s\n", d.var.st_client->aust.aopen.filename);
							printf("flag	  : %d\n", d.var.st_client->aust.aopen.flag);
							printf("mode 	  : %d\n", d.var.st_client->aust.aopen.mode);
							break;
					case 2:	
							printf("--> Read <--\n");
							printf("read fdr : %d\n", d.var.st_client->aust.aread.fdr);
							//printf("buffer	 : %s\n", d.var.st_client->aust.aread.buffr);
							printf("count	 : %d\n", d.var.st_client->aust.aread.countr);
							break;
					case 3:
							printf("--> Write <--\n");
							printf("write fdr : %d\n", d.var.st_client->aust.awrite.fdw);
							printf("buffer	  : %s\n", d.var.st_client->aust.awrite.buffw);
							printf("count	  : %d\n", d.var.st_client->aust.awrite.countw);
							break;
					case 4:
							printf("--> lseek <--\n");	
							printf("write fdr : %d\n", d.var.st_client->aust.alseek.fds);
							printf("offset 	  : %d\n", d.var.st_client->aust.alseek.offset);
							printf("whence 	  : %d\n", d.var.st_client->aust.alseek.whence);
							break;
					case 5:
							printf("--> close <--\n");
							printf("close fdc : %d\n", d.var.st_client->aust.aclose.fdc);
							break;
				}
				break;
		case 2:
		printf("IN server side\n");
		switch(d.var.st_server->type)
				{
					case 1:	
							printf("--> Open <--\n");
							printf("fd : %d\n", d.var.st_server->asust.rp_open.o_fd);
							printf("errno : %d\n", d.var.st_server->asust.rp_open.o_errno);
							break;
					case 2:	
							printf("--> Read <--\n");
							printf("rdval : %d\n", d.var.st_server->asust.rp_read.rdval);
							printf("buffr : %s\n", d.var.st_server->asust.rp_read.buff);
							printf("errno : %d\n", d.var.st_server->asust.rp_read.r_errno);
							break;
					case 3:
							printf("--> Write <--\n");
							printf("wrval : %d\n", d.var.st_server->asust.rp_write.wrval);
							printf("errno : %d\n", d.var.st_server->asust.rp_write.w_errno);
							break;
					case 4:
							printf("--> lseek <--\n");	
							printf("offval : %d\n", d.var.st_server->asust.rp_lseek.l_fd);
							printf("errno : %d\n", d.var.st_server->asust.rp_lseek.l_errno);
							break;
					case 5:
							printf("--> close <--\n");
							printf("close : %d\n", d.var.st_server->asust.rp_close.c_retval);
							printf("errno : %d\n", d.var.st_server->asust.rp_close.c_errno);
							break;
				}
				break;
	}
}
