#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <stdlib.h>
main()
{
	int sfd,retval;
	struct sockaddr_in	server_add,client_add;
	char clidata[] = "mul 12 12";
	char buff[50];
	sfd = socket(AF_INET ,SOCK_STREAM ,0);
	if(sfd == -1)
	{
		printf("in client2 socket failed\n");
		exit(0);
	}

	//printf("sfd %d\n",sfd);
	server_add.sin_family = AF_INET;
	server_add.sin_port   = htons(8787);
	server_add.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sfd,(struct sockaddr*)&server_add,sizeof(server_add)) == -1)
	{
		printf("in client2 connect failed\n");
		exit(0);
	}
	while(1)
	{
		retval = write(sfd,clidata,strlen(clidata));
		if(retval == -1)
		{
			printf("in client2 write failed\n");
			exit(0);
		}
		//printf("in client2 write\n");
		sleep(1);
		retval = read(sfd,buff,sizeof(buff));
		if(retval == -1)
		{
			printf("in client2 read failed\n");
			exit(0);
		}
		buff[retval] = '\0';
		printf("in client2----> %s\n",buff);
	}

}

