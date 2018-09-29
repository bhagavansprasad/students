#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"poll.h"

int main()
{
	struct pollfd fds[20];
	int nfds = 3;

	struct sockaddr_in mysockaddr;
	int socketfd;
	int array[3];
	char buff1[3][15]={"hello","mangalore","bye"};
	char buff[100];
	char sbuff[200];
	int newfd;
	int retval=0,i=0;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("falied to create a socket \r\n");
		exit(1);
	}
	memset(&mysockaddr,0,sizeof(mysockaddr));
	mysockaddr.sin_family=AF_INET;
	mysockaddr.sin_port=htons(6666);
	mysockaddr.sin_addr.s_addr=INADDR_ANY;

	if(bind(socketfd,(struct sockaddr *)&mysockaddr,sizeof(mysockaddr))==-1)
	{
		perror("bind system call falied\r\n");
		close(socketfd);
		exit(1);
	}
	if(listen(socketfd,5)==-1)
	{
		perror("listen system call falied\r\n");
		close(socketfd);
		exit(1);
	}
	//printf("-->server:going for accepting connection\r\n");
	for(i=0; i < 3; i++)
	{
		newfd = accept(socketfd,NULL,NULL);
		//printf("-->the new fd value is %d\n",newfd);
		array[i] = newfd;
		if(newfd==-1)
		{
			perror("accept system call falied\r\n");
			close(socketfd);
			exit(1);
		}
	}

	memset(fds, 0, sizeof(fds));
	
	for(i=0; i < nfds; i++)
	{
		fds[i].fd = array[i];
		fds[i].events = POLLIN;
	}

	while(1)
	{
		printf("-->Waiting on poll()...\n");
		retval = poll(fds, nfds, 0);
		printf("-->poll retval :%d\n", retval);

		for (i = 0; i < nfds; i++)
		{
			printf("%d. revents :%d, %x\n", i, fds[i].revents, fds[i].revents);

			if (fds[i].revents & POLLERR != 0)
			{
				printf("Poll returned POLLERR\n");
				continue;
			}
			if (fds[i].revents & POLLHUP != 0)
			{
				printf("Poll returned POLLHUP\n");
				continue;
			}
	
			if (fds[i].revents & POLLNVAL != 0)
			{
				printf("Poll returned POLLNVAL\n");
				continue;
			}
				
			if(fds[i].revents == POLLIN)
			{
				retval = read(array[i], buff, 30);
				buff[retval]='\0';
				printf("-->Received :%s\n", buff);

				sprintf(sbuff, "S Reply:%s", buff);
				retval = write(array[i], sbuff, strlen(sbuff));

#if 0
				if(strcmp(buff, "bye")==0)
					break;
#endif

			}
		}
		memset(fds, 0, sizeof(fds));
		for(i=0; i < nfds; i++)
		{
			fds[i].fd = array[i];
			fds[i].events = POLLIN;
		}
	}

	close(socketfd);
	return 0;
}

