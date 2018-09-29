#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "struct.h"
#include "second_struct.h"
#include "errno.h"

int rpc_recv_req(struct students *stud , struct school *sch);
int socket_server_init();
int server_read(struct students *stud);
int server_write(struct school *sch);


int main()
{
	int c=0;
	struct students stud;
	struct school sch;
	socket_server_init();

	while(1)
	{
		server_read(&stud);
		rpc_recv_req(&stud , &sch);
		server_write(&sch);
		if(stud.op == 4)
			c++;
		if(c == 2)
			break;
	}
	return 0;
}
