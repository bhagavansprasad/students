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
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
//	char buff1[3][20]={"hi","how are you","bye"};
	char rbuff[1024];
	char wbuff[1024];
	int retval=0,i=0;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.1.36");
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
	    sleep(2);
		gets(wbuff);
	    retval=write(socketfd,wbuff ,20);
		if(retval < 0)
	    {
		   break;
	    }
		printf("--->client: write buff1 retval:      %d\n",retval);

		retval=read(socketfd, rbuff, sizeof(rbuff));
		if(retval < 0)
	    {
		   break;
	    }
		rbuff[retval]='\0';
		printf("--->client: buffer read from server: %s\n",rbuff);
		if(strcmp(rbuff, "bye") == 0)
		break;
	}
	close(socketfd);
	return 0;

}