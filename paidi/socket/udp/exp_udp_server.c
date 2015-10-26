#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

main()
{
	struct sockaddr_in mysockaddr;
	struct sockaddr_in myclientaddr;
	int socketfd;
	char sbuffer[4][20]={"Aura",
	                     "Network",
					     "institute",
						 "Bye"
	                    };
	char rbuffer[100];
	int newfd,i;
	int retval,sd1_retval;

	sd1_retval=sizeof(mysockaddr);

	socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1)
	{
		perror("--->server: failed to  create a socket \n");
		exit(1);
	}

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(4444);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("--->server: bind system call failed\n");
		close(socketfd);
		exit(1);
	}
	printf("--->server: Got the connection request from client \n");

	//while(1)
	for(i=0;i<3;i++)
	{
	    sleep(1);
		retval=recvfrom(socketfd,rbuffer,20,0,(( struct sockaddr *)&mysockaddr), &sd1_retval);
		if(retval < 0)
		{
			perror("--->srvr: recieve failed\n");
			exit(1);

		}
		rbuffer[retval]='\0';
		//printf("--->server: recieve retval:%d\n",retval);
		printf("--->server: recieve data:%s\n",rbuffer);

		retval=sendto(socketfd, &sbuffer[i], 20, 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
		printf("--->server :send retval-->:%d\n",retval);
		if(retval < 0)
		{
			perror("--->server : sending failed\n");
			exit(1);
		}

    } 

}
