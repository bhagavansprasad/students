#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <stdlib.h>
main()
{
	int sfd,retval;
	struct sockaddr_in	server_add;
	char buff[1024];
	char clidata[1024] = "<?xml version='1.0' ?>";
	char cli_1data[1024] = "<stream:stream to='auranetworks.in' xmlns='jabber:client' xmlns:stream='http://etherx.jabber.org/streams' version='1.0'> ";
	char sbuff[1024]="<auth xmlns='urn:ietf:params:xml:ns:xmpp-sasl' mechanism='PLAIN'>AHBhaWRpAGpuam51aAoKCgo=</auth>";
	sfd = socket(AF_INET ,SOCK_STREAM ,0);
	if(sfd == -1)
	{
		printf("in client1 socket failed\n");
		exit(0);
	}

	server_add.sin_family = AF_INET;
	server_add.sin_port   = htons(5222);
	server_add.sin_addr.s_addr = inet_addr("192.168.1.30");

	if(connect(sfd,(struct sockaddr*)&server_add,sizeof(server_add)) == -1)
	{
		printf("in client1 connect failed\n");
		exit(0);
	}
        
		retval = write(sfd,clidata,strlen(clidata));
		retval = write(sfd,cli_1data,strlen(cli_1data));
		//printf("in client write1 retunval---->= %d\n",retval);
	       //printf("in client write2 data---->= %s\n",cli_1data);
		
		retval = read(sfd,buff,sizeof(buff));
		printf("in client1 read retunval----= %d\n",retval);
		printf("in client1 read----> %s\n",buff);

		retval = read(sfd,buff,sizeof(buff));
		printf("in client2 read retunval----= %d\n",retval);
		printf("in client2 read----> %s\n",buff);

		retval = write(sfd,sbuff,strlen(sbuff));
	//	printf("in client1 write retunval---->= %d\n",retval);

		retval = read(sfd,buff,sizeof(buff));
		printf("in client3 read retunval----= %d\n",retval);
		printf("in client3----> %s\n",buff);

/*		retval = write(sfd,bbuff,strlen(bbuff));
		printf("in client4 write retunval---->= %d\n",retval);
		
        retval = read(sfd,buff,sizeof(buff));
		printf("in client4 read retunval----= %d\n",retval);
		printf("in client4 read----> %s\n",buff);*/

	      

  close(sfd);
}


/*
Authentication sequence
========================
The “PLAIN” authorization method is the simplest among them. It works as following. 
Client: Client send a stream with selected authorization method with base64 encoded user name and password. 
	    The user name and password are allocated in format of “\0UserName\0Password”. 
		For example, i would like to log on as “mbed@ceit.org”, whose password is “mirror”. 
		And, the string to be send to encoder is “\0mbed\0mirror”, and the encoded string is “AG1iZWQAbWlycm9y”. 
		Then, the client sends the following stream to server. 
		<auth xmlns='urn:ietf:params:xml:ns:xmpp-sasl' mechanism='PLAIN'>AG1iZWQAbWlycm9y</auth> 

Server: If the server accept the authorization, it sends back a stream with “success” tag. 
        <success xmlns='urn:ietf:params:xml:ns:xmpp-sasl'/> 
		or: Server: If the password does not match the user name, or there is an error on encoding, 
		the server will sends a failure stream. 
		<failure xmlns='urn:ietf:params:xml:ns:xmpp-sasl'/> 
		
		Details of “DIGEST-MD5” authorization can be found at http://www.ietf.org/rfc/rfc2831.txt. 

http://ostermiller.org/calc/encode.html
*/
