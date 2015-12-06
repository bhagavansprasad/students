#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"

char buff1[3][20]={"hi","how are you","bye"};
main(int argc, char *argv[])
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char sbuff[1024];
	int retval=0,i=0;
	char cbuff[100];
	int duration = 0;

	duration = atoi(argv[1]);

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
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
		exit(1);
	}
	while(i < 3)
	{
		//sprintf(buff1[i], "%d: Iam client", getpid());
		sprintf(cbuff, "C:%d %s", getpid(), buff1[i]);
		retval=write(socketfd, cbuff, strlen(cbuff));
		if(retval < 0)
		{
			break;
		}
		i++;
		printf("--->client: write buff1 retval:      %d\n",retval);

		
		printf("--->client: reading from server......\n");
		retval=read(socketfd, sbuff, sizeof(sbuff));
		if(retval < 0)
		{
			break;
		}
		sbuff[retval]='\0';
		printf("--->client: buffer read from server: %s\n",sbuff);
		if(strcmp(sbuff,"bye")==0)
			break;

		sleep(duration);
	}

	close(socketfd);
	return 0;

}
