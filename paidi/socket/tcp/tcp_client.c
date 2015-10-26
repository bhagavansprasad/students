#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"

int main(void)
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char cbuff[1024]="hi im client1";
	char sbuff[1024];
	int retval=0;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(9999);

	printf("--->client: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(socketfd);
		exit(1);
	}

	while(1)
	{ 
        sleep(1); 
		retval=write(socketfd, cbuff,10);
		if(retval < 0)
		{
			close(socketfd);
			break;
		}
		printf("--->client: write retval:%d\n",retval);
	
		retval=read(socketfd, sbuff, 10);
		if(retval < 0)
		{
			close(socketfd);
			break;
		}
        sbuff[retval]='\0';
		printf("--->client: read retval:%d\n",retval);
		printf("--->client: buffer read from server:%s\n",sbuff);

	}
	close(socketfd);

	return 0;

}
























/*#include"sys/types.h"
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
	struct sockaddr_in myclientaddr;
	char cbuff[100]="hi";
	char sbuff[1024];
	int retval=0,i=0;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(8888);

	printf("--->client: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(socketfd);
		exit(1);
	}

//	while(1)
	//{ 
	   for(i=0;i<=7;i++)
	   {
	    retval=write(socketfd, cbuff,10);
		printf("--->client: write retval:%d\n",retval);
		if(retval < 0)
		{
			//break;
		}

        sleep(2);
	    retval=write(socketfd, cbuff,5);
		printf("--->client: write retval:%d\n",retval);
        }

     #if 0
		retval=read(socketfd, sbuff, 10);
		printf("--->client: read retval:%d\n",retval);
		if(retval < 0)
		{
			break;
		}
         sbuff[retval]='\0';
		printf("--->client: buffer read from server:%s\n",sbuff);
    #endif
	//}
//	close(socketfd);

	//return 0;

}
*/
