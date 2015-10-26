#include<stdio.h>
#include<stdlib.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include "rpc_structs.h"

int s_sockfd = -1;
int nsockfd = -1;
st_dump dmp;
char *buff;

void main(int argc , char *argv[])
{
	asuds reply;
	auds d;

	if((s_sockfd = s_comminit()) ==  -1)
	{
		printf("Failed to communicate\n");
		exit(1);
	}	

	//Receive a message from client
	while(recv(nsockfd, (void *)&d, sizeof(auds), 0) > 0)
	{
		//printf("Receive failed in server side\n");
		//exit(1);


		printf("\nCalling core dump after recv in server side\n");
		dmp.type = 1;
		dmp.var.st_client = &d;
		dump_call(dmp);

		switch(d.status)
		{
			case 1: 
				rpcs_open(&reply, &d);
				break;

			case 2: 
				rpcs_read(&reply, &d);
				break;

			case 3: 
				rpcs_write(&reply, &d);
				break;

			case 4: 
				rpcs_lseek(&reply, &d);
				break;

			case 5: 
				rpcs_close(&reply, &d);
				break;

			default: 
				printf("No match in server calls\n");
				break;
		}

		printf("\nCalling Core dump before send in server side\n");
		dmp.type = 2;
		dmp.var.st_server = &reply;
		dump_call(dmp);

		if(send(nsockfd, (void *)&reply, sizeof(asuds), 0) < 0)
		{
			printf("Sending failed in server side\n");
			exit(1);
		}
	}
	
	sleep(2);
	printf("NO more thing to receive\n\n");
	printf("Task accomplished and exiting server\n\n");
	exit(1);

	//sleep(10);
	//return 0;
}

