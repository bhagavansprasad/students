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

int socketfd = -1, newfd = -1;
void tcp_server_init()
{
	struct sockaddr_in mysockaddr;
//	char buff1[3][20]={"hellow","i am fine","bye"};
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
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

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
	}

	printf("--->server : Going for accepting connection \r\n");
	newfd = accept(socketfd,NULL,NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
	}

	printf("--->server : Got the connection request from client \r\n\n");
}
void server_read_data(struct final *c_req )
{

	int retval ;
	retval = read(newfd, c_req, sizeof(struct final));
	printf("in server read rval is : %d\n",retval);
}
void server_send_data(struct S_final *s_rply)
{
	int retval ;
	retval=write(newfd,s_rply, sizeof(struct S_final));
	printf("in server write rval is : %d\n",retval);
}
void close_socket()
{
	printf("-------> closing of a socket <---------\n");
 	close(socketfd);
}
#if 0
for(i=0;i<3;i++)
{
			sleep(2);
	        retval = read(newfd, buffer, 30);
			if(retval < 0)
	     	{
			   break;
	    	}
            buffer[retval]='\0';
	        printf("--->server:  receive from client :%s\r\n",buffer);

            retval=write(newfd, &buff1[i], 20);
			if(retval < 0)
		    {
		      break;
		    }
			printf("--->server: buff1 write retval : %d\n",retval);

		}
            close(socketfd);
			return 0;

}
#endif

