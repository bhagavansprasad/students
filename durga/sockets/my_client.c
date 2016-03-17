#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

main(int argc, char argv[])
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	//char buff1[3][20]={"hi","how are you","bye"};
	char sbuff[1024];
	char buff1[20];
	int retval=0,i=0;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(4444);

	printf("--->client: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(socketfd);
		exit(1);
	}
	//for(i=0;i<3;i++)
	printf("begin chat\n");
	while(1)
	{
	    sleep(2);
		gets(buff1);
	    retval=write(socketfd, buff1, 20);
		if(retval < 0)
	    {
		   break;
	    }

		//printf("--->client: write buff1 retval:      %d\n",retval);

		retval = read(socketfd, sbuff, sizeof(sbuff));
		if(retval < 0)
	    {
		   break;
	    }
		sbuff[retval]='\0';
		printf("%s\n",sbuff);
		if(strcmp(buff1,"bye")==0)
			break;
		//printf("--->client: buffer read from server: %s\n",sbuff);
	}
	close(socketfd);
	return 0;

}
