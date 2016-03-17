#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include<poll.h>

int array[5];
int nfds=3;

int main()
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	//char buff1[3][20]={"hellow","i am fine","bye"};
	char ruffer1[100];
	char ruffer2[100];
	char ruffer3[100];
	char wuffer1[100];
	char wuffer2[100];
	char wuffer3[100];

	int newfd,firstfd;
	int retval = 0,i,j=0;
	int pid;
	int available_fds;

	struct pollfd fds[5];
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(6666);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	for(i=0;i<3;i++)
	{
		printf("--->server : Going for accepting connection \r\n");
		newfd = accept(socketfd,NULL,NULL);
		if(newfd == -1)
		{
			perror("accept system call failed\r\n");
			close(socketfd);
			exit(1);
		}
		array[i]=newfd;
		printf("--->server : Got the connection request from client \r\n\n");
	}
	memset(fds, 0 , sizeof(fds));

	for(i=0;i<3;i++)
	{
		fds[i].fd = array[i];
		fds[i].events = POLLIN;

	}
	while(1)
	{
		sleep(5);
		printf("Waiting on poll()...\n");
		retval=poll(fds,nfds,0);
		printf("poll retval is %d\n",retval);
		for (i = 0; i < nfds; i++)
		{
			printf("%d.revents:%d,%x\n",i,fds[i].revents,fds[i].revents);
			#if 0
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
			  #endif

			if(fds[i].revents==POLLIN)	
			{
				printf("available fd is %d\n",fds[i].revents);	
				retval = read(array[i], ruffer1, 30);
				if(retval < 0)
				{
					break;
				}
				ruffer1[retval]='\0';
				printf("--->server:  receive from client :%s\r\n",ruffer1);
				printf("------->enter message for client1:\n");
				gets(wuffer1);
				retval=write(array[i], wuffer1,30);
				if(retval < 0)
				{
					break;
				}
				printf("--->server: buff1 write retval : %d\n",retval);
				if(strcmp(ruffer1, "bye") == 0)
				{
						close(array[i]);
						available_fds=delete_fd_by_value(array[i]);
						printf("no of fds is %d\n",available_fds);
						break;
					
				}
			}
		}
		memset(fds, 0, sizeof(fds));
		for(i=0; i < available_fds; i++)
		{
			fds[i].fd = array[i];
			fds[i].events = POLLIN;
		}
		nfds=available_fds;


		close(socketfd);
	}

	return 0;
}


int delete_fd_by_value(int fd)
{
	int count=0,j,i,k;

	for(i=0;i<nfds;i++)
	{
		if(array[i]==fd)
		{
			for(k=i;array[k]!=0;k++)
			{
				array[k]=array[k+1];

			}
			for(j=0;array[j]!=0;j++)
			{
				count++;
			}
			return(count);
		}
	}
}
