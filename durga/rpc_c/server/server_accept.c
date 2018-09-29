#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"structer.h"
#include"server_structer.h"
#include <fcntl.h>
int socketfd;
int newfd;

struct data p;
struct server s;

void server_accept(void)
{
	struct sockaddr_in mysockaddr;
	int retval = 0;
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd == -1)
	{
		perror("failed to create a socket \r\n");
		exit(1);
	}
	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(6666);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd,5) == -1)
	{
		perror("listen system call failed \r\n");
		close(socketfd);
		exit(1);
	}

	printf("------>server : Going for accepting connection \r\n");
	newfd = accept(socketfd, NULL, NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);

	}
	printf("----->server : got the connection requset from client \r\n\n");
}




/*function for reading the file*/

int server_read( struct data *p)
{

	 int rval = read(newfd, p, sizeof(struct data));
	 printf("in server read rval is : %d\n",rval);

} 

/* function for write data*/

int server_write( struct server *s)
{
	 int rval = write( newfd, s, sizeof( struct server));
	 printf("in server write rval is : %d\n",rval);
}
