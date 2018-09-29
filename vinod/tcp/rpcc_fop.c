#include <stdlib.h>
#include "rpc_structs.h"

extern asuds d1;
extern c_sock;
extern st_dump dmp;
extern char *buffer;

void rpccfop(auds *d)
{
	printf("\nCalling Core dump before send in client side\n");
	dmp.type = 1;
	dmp.var.st_client = d;
	dump_call(dmp);
	if(send(c_sock , d , sizeof(auds) , 0) < 0)
	{	
		perror("Sending failed in client side");
		exit(1);
	}
	
	if(recv(c_sock, (void *)&d1, sizeof(asuds), 0) < 0)
	{
		perror("receive failed in client side");
		exit(1);
	}
	printf("\nCalling Core dump after recv in client side\n");
	dmp.type = 2;
	dmp.var.st_server = &d1;
	dump_call(dmp);
}
