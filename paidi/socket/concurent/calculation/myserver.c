#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


int convert_input(int arr[],char *buff)
{

	int i=0,j=0,a=0,k=0,sum=0,mul=1,sub=0,div=1;
	char cmd[5];
	for(i=0;buff[i] == ' ' && buff[i] != '\0';i++);

	for( ;( cmd[j] = buff[i] ) !=' ' & buff[i] != '\0';i++,j++);
	cmd[j] = '\0';
	for(; buff[i] == ' '  && buff[i] != '\0';i++);
	for(;buff[i] != ' '  && buff[i] != '\0';i++)
		a=a*10+(buff[i] - '0');
	arr[k++] = a;
	a=0; 
	for(; buff[i] == ' '  && buff[i] != '\0';i++);
	for(;buff[i] != ' ' && buff[i] != '\0';i++)
		a=a*10+(buff[i] - '0');
	arr[k++] = a;
	arr[k] = '\0';
	if( strcasecmp(cmd,"add") ==0 )
	{
		for(i=0;arr[i] != '\0';i++)
		sum = sum + arr[i];
		return sum;
	}
	else if(strcasecmp(cmd,"MUL")==0)
	{
		for(i=0;arr[i] != '\0';i++)
			mul = mul * arr[i];
		return mul;
	}
	else if( strcasecmp(cmd,"SUB") ==0)
	{
		for(i=0;arr[i] != '\0';i++)
			sub = arr[i]-sub;
		return -sub;
	}
	else if( strcasecmp(cmd,"DIV") ==0 )
	{
		div = arr[0]/arr[1];
		return div;
	}
	else
	{
	printf("please chesk the command\n");
	return 0;
	}
}

main()
{
	int nfd,sfd,cfd,retval=0,r=0,sum = 0,i=3,a=0,b=0;
	struct sockaddr_in	server_add,client_add;
	char buff[50];
	int N[20];
	char srvdata[50];

	sfd = socket(AF_INET ,SOCK_STREAM ,0);
	if(sfd == -1)
	{
		printf("in server socket failed\n");
		exit(0);
	}
	//memset(&server_add,0,sizeof(struct sockaddr_in));

	server_add.sin_family = AF_INET;
	server_add.sin_port    = htons(9000);
	server_add.sin_addr.s_addr = INADDR_ANY;

	if(bind(sfd,((struct sockaddr*)&server_add),sizeof(server_add)) == -1)
	{
		printf("in server bind failed\n");
		exit(0);
	}
	//printf("----server accepting the connection\n");
	if(listen(sfd,5) == -1)
	{
		printf("in server listen failed\n");
		exit(1);
	}

while(1)
	{
		nfd = accept(sfd,NULL,NULL);
		if(nfd ==-1)
		{
			printf("in server accept failed\n");
			exit(0);
		}
		if(fork() == 0)
		{
		while(1)
		{	
			sleep(1);
			retval = read(nfd,buff,10);
			if(retval < 0)
			{
			perror("in server read failed\n");
			break;
			}
			buff[retval] = '\0';
			printf("in server : %s\n",buff);
			int opval = convert_input(N,buff);
			sprintf(srvdata,"%d %s",opval,buff);
			retval = write(nfd,srvdata,strlen(srvdata));
			if(retval < 0)
			{
				perror("in server write failed\n");
				break;
			}
		}
		close(nfd);
		}
	}
}
