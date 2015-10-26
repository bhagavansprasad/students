#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"

main()
{
	int socketfd;
	int connected;
	struct sockaddr_in mysockaddr;
	struct sockaddr_in myclientaddr;
	char cbuff[4][20]= {"stay in",
	                    "Bommanahalli",
						"Bangalore",
						"Bye"
					   };
	char rbuffer[100];
	int retval,sd1_retval,i;
    sd1_retval = sizeof(mysockaddr); 
	socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(4444);
	mysockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("--->client: Connecting to the server\n");
	//while(1)
	for(i=0;i<3;i++)
	{
		sleep(1);
		retval=sendto(socketfd, &cbuff[i], 20, 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
		//printf("--->client:send retval-->:%d\n",retval);
		if(retval < 0)
		{
			perror("--->client: sending failed\n");
			exit(1);
		}
        retval=recvfrom(socketfd,rbuffer,20,0,(( struct sockaddr *)&mysockaddr), &sd1_retval);
		if(retval < 0)
		{
			perror("--->client: recieve failed\n");
			exit(1);
		}
		rbuffer[retval]='\0';
		//printf("--->client: recieve retval:%d\n",retval);
		printf("--->client: recieve data:%s\n",rbuffer);
	}     
	
}


