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
int array_num = 0;

void main(int argc , char *argv[])
{
	asuds reply;
	auds d;
	sgets s;
	int i = 0;

	char array[][8] = {
		{10,20,30,40,50,60,70,80},
		{80,70,60,50,40,30,20,10},
		{1,2,3,4,5,6,7,8},
		{8,7,6,5,4,3,2,1}
	};


	if((s_sockfd = s_comminit()) ==  -1)
	{
		printf("Failed to communicate\n");
		exit(1);
	}	

	while(recv(nsockfd, (void *)&s, sizeof(s), 0) > 0)
	{
		i++;
		switch(s.select)
		{	
			case 1: rpcs_getf(array);
					break;
			case 2: rpcs_getn(array, &s);
					break;
			case 3: rpcs_getp(array, &s);
					break;
			case 4: rpcs_getl(array);
					break;
		}

		if(send(nsockfd, (void *)&array_num, sizeof(int), 0) < 0)
		{
			printf("Sending failed in server side\n");
			exit(1);
		}
	}

	/*	sleep(2);
		printf("NO more thing to receive\n\n");
		printf("Task accomplished and exiting server\n\n");
		exit(1);
		}

	 */
if(i == 0)
{
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
}

sleep(2);
printf("NO more thing to receive\n\n");
printf("Task accomplished and exiting server\n\n");

//exit(1);
//sleep(10);
//return 0;

}
