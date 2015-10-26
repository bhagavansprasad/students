#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "structer.h"
#include "server_structer.h"

int socketfd = -1;
struct server s ;
struct data p;

void client_requst()
{
	int connected;
	struct sockaddr_in myclientaddr;
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if ( socketfd == -1)
	{
		perror("---->client:Failed tocreat a socket\n");
		exit(1);
	}
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(6666);

	printf("---->client: connecting to the server\n");
	connected = connect( socketfd, (struct	sockaddr*)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("----->client: connect system call failed\n");
		close(socketfd);
		exit(1);
	}

}
/*function to client_write*/

int client_write ( struct data *p)
{
	int w;
	w = write(socketfd, p, sizeof(struct data));
	printf("----->client:write retun value: %d\n",w);
	return w;
}
/*function to client_read */

int client_read( struct server *s)
{
	int r ;
	r = read(socketfd, s, sizeof(struct server ));
	printf("-------->client: read  return value from server : %d\n",r);
	return r;
}
