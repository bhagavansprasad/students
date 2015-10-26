#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"struct_req.h"
#include"struct_rply.h"

int socketfd;
void tcp_client_init()
{
	int connected;
	struct sockaddr_in myclientaddr;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(6666);

	printf("--->client: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(socketfd);
	}
}
void client_send_data(struct final *c_req)
{
	int rval = write(socketfd,c_req,sizeof(struct final));
	printf("write rval is : %d\n",rval);
}
void client_read_req(struct S_final *s_rply)
{	
	int rval; 
	rval = read(socketfd, s_rply, sizeof(struct S_final));
}
#if 0 
for(i=0;i<3;i++)
{
	sleep(2);
	retval=write(socketfd, &buff1[i],20);
	if(retval < 0)
	{
		break;
	}
	printf("--->client: write buff1 retval:      %d\n",retval);

	retval=read(socketfd, sbuff, sizeof(sbuff));
	if(retval < 0)
	{
		break;
	}
	sbuff[retval]='\0';
	printf("--->client: buffer read from server: %s\n",sbuff);
}
close(socketfd);
return 0;

}
#endif
