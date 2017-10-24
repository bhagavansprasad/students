#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"poll.h"
#include"fcntl.h"

int main()
{
	struct pollfd fds[20];
	int nfds = 1;

	struct sockaddr_in mysockaddr;
	int socketfd;
	int array[3];
	char buff1[3][15]={"hello","mangalore","bye"};
	char buff[100];
	char sbuff[200];
	int newfd;
	int retval=0,i=0,j=0,k=0,f=0;
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

/*	memset(fds, 0, sizeof(fds));
	
	for(i=0; i < nfds; i++)
	{
		fds[i].fd = array[i];
		fds[i].events = POLLIN;
	}*/

	fds[0].fd=socketfd;
	fds[0].events=POLLIN;


	while(1)
	{

		sleep(5);

		
		printf("-->Waiting on poll()...\n");
		retval = poll(fds, nfds, 6);
		printf("-->poll retval :%d\n", retval);

		if (retval < 0)
		{
			perror("  poll() failed");
			break;
		}

		if (retval == 0)
		{
			printf("  poll() timed out.  End program.\n");
		//	break;
		}

	
	for(  ; k < nfds; k++)
	{
		
	//	f=fcntl(socketfd,F_SETFL,O_NONBLOCK);

	//	printf("f:%d\n",f);
		

		if(fds[k].revents==POLLIN)
		{

			newfd = accept(socketfd,NULL,NULL);
			printf("-->the new fd value is %d\n",newfd);
	
			if(newfd!=-1)
			{
				fds[k].fd = newfd;
				fds[k].events=POLLIN;
				nfds++;
			}	

			if(newfd==-1)
			{
				perror("accept system call falied\r\n");
				break;
			//	close(socketfd);
			//	exit(1);
			}
		}
	}	


		for (i = 0; i < nfds; i++)
		{
		//	printf("%d. revents :%d, %x\n", i, fds[i].revents, fds[i].revents);

		/*	if (fds[i].revents & POLLERR != 0)
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
			}*/

			
				
			if(fds[i].revents == POLLIN)
			{
				retval = read(fds[i].fd, buff, 30);
				if(buff==NULL)
					break;
				buff[retval]='\0';
				printf("-->Received %d:%s\n",i, buff);

				sprintf(sbuff, "%s", buff);
				retval = write(fds[i].fd, sbuff, strlen(sbuff));


				if(strcmp(buff, "bye")==0)
				{

					fds[i].fd=-1;

					close(fds[i].fd);
					
					
				}

			}

		}
			
			for (i = 0; i < nfds; i++)
			{
				if (fds[i].fd == -1)
				{
					for(j = i; j < nfds; j++)
					{
						fds[j].fd = fds[j+1].fd;
					}
					i--;
					nfds--;
				}
			}
		



			
		
	//	memset(fds, 0, sizeof(fds));

		
	/*	for(i=0; i < nfds; i++)
		{
			fds[i].fd = array[i];
			fds[i].events = POLLIN;
		}*/

		printf("nfds:%d\n",nfds);
	}

	close(socketfd);
	return 0;
}

