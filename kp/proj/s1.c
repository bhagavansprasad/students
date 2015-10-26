/*    C socket server example
 */

#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
//#include<unistd.h>    //write
#include"define.h"

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[2000];
	fop_data datac ; 
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket\n");
	}
	printf("Socket created\n");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );

	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error\n");
		return 1;
	}
	printf("bind done\n");

	//Listen
	listen(socket_desc , 3);

	//Accept and incoming connection
	printf("Waiting for incoming connections...\n");
	c = sizeof(struct sockaddr_in);

	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed\n");
		return 1;
	}
	printf("Connection accepted\n");

	//Receive a message from client
	while(read_size = recv(client_sock,(char *)&datac, sizeof(fop_data), 0) > 0 )
	{
		int retval;
		switch(datac.cmd)
		{
			case FILE_OPEN:
				retval = aopen(datac.udata.opn.fname, datac.udata.opn.mode);

				datac.udata.opn.fd = retval;

				//	return retval;
				//	 send(client_sock ,(char*)retval ,sizeof(retval));
				break;

			case FILE_READ:
				retval = aread( datac.udata.rdwt.fd, datac.udata.rdwt.buffer, datac.udata.rdwt.count);

				datac.udata.rdwt.count = retval;

				//return retval;
				//	 send(client_sock ,(char*)retval ,sizeof(retval));
				break;

			case FILE_WRITE:
				retval = awrite( datac.udata.rdwt.fd, datac.udata.rdwt.buffer, datac.udata.rdwt.count);

				datac.udata.rdwt.count = retval;

				//return retval;
				//	 send(client_sock ,(char*)retval ,sizeof(retval));
				break;

			case FILE_SEEK:
				retval = alseek(datac.udata.seek.fd, datac.udata.seek.offset, datac.udata.seek.whence);

				datac.udata.seek.offset=retval;

				//return retval;
				// send(client_sock ,(char*)retval ,sizeof(retval));
				break;

			case FILE_CLOSE:
				aclose(datac.udata.cls.fd);
				break;

			default:
				printf("-->%s, %s, %d ***PANIC*** Received Invalid command :%d\n", __FILE__, __FUNCTION__, __LINE__, datac.cmd);
			    exit(1);

	    }



	    }

	    if(read_size == 0)
	    {
		    printf("Client disconnected");
		    fflush(stdout);
	    }
	    else if(read_size == -1)
	    {
		    perror("recv failed");
	    }

	    return 0;
}
