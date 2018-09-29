#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"
#include "structure.h"

int serversocket;
int acceptfd;

int init_nets_communication(int srvr_port)
{
	struct sockaddr_in mysockaddr;
	serversocket = socket(AF_INET, SOCK_STREAM,0);
	if(serversocket < 0)
	{
		perror("--->server : failed to  create a server socket \r\n");
		printf("socket errno = %d\n",errno);
		exit(1);
	}
	printf("--->server : server socket is created successively\n");

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(srvr_port);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(serversocket, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) < 0 )
	{
		perror("bind system call failed\r\n");
		printf("bind errno = %d\n",errno);
		close(serversocket);
		exit(1);
	}
	printf("--->server : binding wellknown address to socket is successful\n");


	if(listen(serversocket, 5) == -1)
	{
		perror("listen system call failed\r\n");
		printf("listen errno = %d\n",errno);
		close(serversocket);
		exit(1);
	}
	printf("--->server : listening is successful and going for accepting connection... .. . \n");
	acceptfd = accept(serversocket,NULL,NULL);
	if(acceptfd == -1)
	{
		perror("--->server : accept system call is failed\r\n");
		printf("accept errno = %d\n",errno);
		close(serversocket);
		exit(1);
	}

	printf("--->server : got the connection request from client \r\n\n");
	return serversocket;
}

int server_read_from_client(fop_data_req *creq)
{
	int rretval;

	rretval = read(acceptfd, creq, sizeof(fop_data_req));
	printf("     ------******------ \n");
	printf("SERVER : server recieving data retval...................... = %d\n",rretval);

	return rretval;
}

int server_write_to_client(fop_data_rep *sreplay)
{
	int wretval;

	wretval = write(acceptfd, sreplay, sizeof(fop_data_rep));

	printf("SERVER : server sending data retval........................ = %d\n",wretval);

	return wretval;
}

int close_nets_communication(void)
{

	close(acceptfd);

	close(serversocket);

	return 0;
}
