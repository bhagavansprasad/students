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
	int socket_desc , client_sock , c , retval;
	struct sockaddr_in server , client;

	fop_data datac ; 
	fop_data reply;
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
		perror("Bind failed ");
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
	while((retval = recv(client_sock,(char *)&datac, sizeof(fop_data), 0)) > 0 )
	{
		printf ("recv retval :%d\n", retval);
		switch(datac.cmd)
		{
			case FILE_OPEN:
				retval = aopen(datac.udata.opn.fname, datac.udata.opn.mode);
			// 	printf("flie name :%s\n",datac.udata.opn.fname);
			// 	printf("mode:%d\n",datac.udata.opn.mode);
				datac.udata.opn.fd =retval;

				printf("srvr :%d\n", datac.udata.opn.fd);
				//	return retval;
				send(client_sock ,(char*)&datac, sizeof(fop_data), 0);
				break;


			case FILE_READ:
				retval = aread( datac.udata.rdwt.fd, datac.udata.rdwt.buffer, datac.udata.rdwt.count);

				datac.udata.rdwt.count = retval;
				printf("srvr read :%d\n", datac.udata.rdwt.count);

				//return retval;
				send(client_sock ,(char*)&datac ,sizeof(fop_data),0);
				break;


			case FILE_WRITE:
				retval = awrite( datac.udata.rdwt.fd, datac.udata.rdwt.buffer, datac.udata.rdwt.count);

				datac.udata.rdwt.count = retval;
				send(client_sock ,(char*)&datac ,sizeof(fop_data),0);
				break;

				//return retval;


			case FILE_SEEK:
				retval = alseek(datac.udata.seek.fd, datac.udata.seek.offset, datac.udata.seek.whence);

				datac.udata.seek.offset=retval;
				send(client_sock ,(char*)&datac ,sizeof(fop_data),0);
				break;

				//return retval;
				

			case FILE_CLOSE:
				aclose(datac.udata.cls.fd);
				break;

			default:
				printf("-->%s, %s, %d ***PANIC*** Received Invalid command :%d\n", __FILE__, __FUNCTION__, __LINE__, datac.cmd);
			    exit(1);

	    }



	    }

	    if(retval == 0)
	    {
		    printf("Client disconnected");
		    fflush(stdout);
	    }
	    else if(retval == -1)
	    {
		    perror("recv failed");
	    }

	    return 0;
}
