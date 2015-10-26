#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <stdlib.h>
main()
{
	int sfd,retval,i;
	struct sockaddr_in	server_add;
	char clidata[3][20] = {"who","how r u","bye"};
	char buff[50];
	sfd = socket(AF_INET ,SOCK_STREAM ,0);
	if(sfd == -1)
	{
		printf("in client1 socket failed\n");
		exit(0);
	}

	//printf("sfd %d\n",sfd);
	server_add.sin_family = AF_INET;
	server_add.sin_port   = htons(9999);
	server_add.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sfd,(struct sockaddr*)&server_add,sizeof(server_add)) == -1)
	{
		printf("in client1 connect failed\n");
		exit(0);
	}
	for(i=0;i<3;i++)
	{  
	    sleep(1);
		retval = write(sfd,&clidata[i],50);
		if(retval < 0)
		{
		    break;
		}
		//printf("in client1 write\n");
		sleep(1);
		retval = read(sfd,buff,sizeof(buff));
		if(retval < 0)
		{
		    break;
		}
		buff[retval] = '\0';
		printf("in client1----> %s\n",buff);
	}
  close(sfd);
}

