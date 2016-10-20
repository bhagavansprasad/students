/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int welcomeSocket, newSocket ;
	
	struct bufer
	{
	 int length = 10;
	 char buff[50];
	}b;
	
	//char buffer[256] ;
	struct sockaddr_in serverAddr ;
	struct sockaddr_storage serverStorage ;
	socklen_t addr_size ;

	/*---- Create the socket. The three arguments are: ----*/
	/* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

	/*---- Configure settings of the server address struct ----*/
	/* Address family = Internet */

	serverAddr.sin_family = AF_INET;

	/* Set port number, using htons function to use proper byte order */

	serverAddr.sin_port = htons(8080);

	/* Set IP address to localhost */

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* Set all bits of the padding field to 0 */

	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	/*---- Bind the address struct to the socket ----*/

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	/*---- Listen on the socket, with 5 max connection requests queued ----*/

	if(listen(welcomeSocket, 5) == 0)

		printf("Listening\n");

	else 
		printf(" Error\n ");

	/*---- Accept call creates a new socket for the incoming connection ----*/

	addr_size = sizeof serverStorage;
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

	/*---- Read the message from the server into the buffer ----*/
      
	  b.length = 20;
	  strcpy(b.buff,"hai\n");

	  recv(newSocket,b.length->20, b.buff->hai , 256, 0);
	printf("data recived : %s\n", &b); 

	/*---- Send message to the socket of the incoming connection ----*/

//strcpy(bufer,"Hai\n");
	//strcpy(buffer, "this is\n");

	send(newSocket, &b, 13, 0) ;

	return 0;
}
