#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "struct_req.h"
#include "struct_replay.h"
void debug_before_write(struct final *);

int client_sock_fd = -1;

int tcp_client_init(void)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	int connected;
	struct sockaddr_in myclientaddr;

	client_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_sock_fd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.0.30 ");
	myclientaddr.sin_port = htons(10000);

	printf("--->client: Connecting to the server\n");
	connected = connect(client_sock_fd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(client_sock_fd);
		exit(1);
	}

	return 0;
}

int client_send_data(struct final *c_req)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	int retval = 0;

	debug_before_write(c_req);

	retval = write(client_sock_fd, c_req, sizeof(struct final));

	printf("-->C. write socket retval :%d\n", retval);	

	return retval;

}

int client_read_reply(struct S_final *preply)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	int retval = 0;

	//debug_before_write(c_req);

	retval = read(client_sock_fd, preply, sizeof(struct S_final));

	printf("-->C. read socket retval :%d\n", retval);	

	return retval;

}
