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
	int socketfd,len;
	//char buff1[3][15]={"hello","mangalore","bye"};
	char buff[100];
	char sbuff[200];
	int newfd=-1;
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

	memset(fds, 0, sizeof(fds));
	fds[0].fd=socketfd;
	fds[0].events = POLLIN;

	while(1)
	{
		printf("-->Waiting on poll()...\n");
		retval = poll(fds, nfds, 0);
		if(retval<0)
		{
			perror("poll() failed\n");
			break;
		}
		printf("-->poll retval :%d\n", retval);


		for (i = 0; i < nfds; i++)
		{
			printf("error! revents=%d\n", fds[i].revents);
			if(fds[i].revents==0)
				continue;

			if (fds[i].revents != POLLIN)
			{
				printf("error! revents=%d\n", fds[i].revents);
				break;
			}

			if(fds[i].fd==socketfd)
			{
				printf("socketfd is readable\n");
				newfd=accept(socketfd,NULL,NULL);
				if(newfd<0)
				{
					perror("accept failed()");
					break;
				}
				printf("connection is established %d\n",newfd);
				fds[nfds].fd=newfd;
				fds[nfds].events=POLLIN;
				nfds++;
				if(newfd==-1)
					break;
			}
			else
			{
				printf("fd is readable %d\n",fds[i].fd);
				while(1)
				{
					retval = read(fds[i].fd, buff,sizeof(buff));
					buff[retval]='\0';
					printf("-->Received :%s\n", buff);

					len=retval;
					//sprintf(sbuff, "S Reply:%s", buff);
					retval = write(fds[i].fd, buff,len);
				}
			}

		}
	}
	close(socketfd);
	return 0;
}

