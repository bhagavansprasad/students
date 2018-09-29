#include "udp.h"
udp_contex_blk udp_cb;
main()
{
	int socketfd,port=0;
	int connected,sfd;
	struct sockaddr_in mysockaddr;
	struct sockaddr_in myclientaddr;
	char buff[1024];
	char sbuff[1024];
	char *urlptr;
	int i,len=0,retval=0,sd1_retval;
	socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}
	udp_cb.fd = socketfd;
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr("239.255.255.250");
	mysockaddr.sin_port = htons(1900);

	sd1_retval=sizeof(mysockaddr);

	printf("--->client: Connecting to the server\n");

	len += sprintf(buff, "%s", "M-SEARCH * HTTP/1.1\r\n");
	len += sprintf(buff+len, "%s", "HOST: 239.255.255.250:1900\r\n");
	len += sprintf(buff+len, "%s", "MAN: \"ssdp:discover\"\r\n");
	len += sprintf(buff+len, "%s", "MX: 5\r\n");
	len += sprintf(buff+len, "%s", "ST: ssdp:all\r\n");
	len += sprintf(buff+len, "%s", "\r\n");

	//printf("-->buff len :%d\n", strlen(buff));
	printf("-->buff :%s\n", buff);
	retval=sendto(socketfd, buff, strlen(buff), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	retval=sendto(socketfd, buff, strlen(buff), 0, ((struct sockaddr *)&mysockaddr), sizeof(mysockaddr));
	//printf("--->client:send retval-->:%d\n",retval);
	if(retval < 0)
	{
		perror("--->client: sending failed\n");
		exit(1);
	}
	for(i=0; i<=100; i++)
	{

		//sleep(1);
		retval=recvfrom(socketfd,sbuff,sizeof(sbuff),0,((struct sockaddr *)&mysockaddr),&sd1_retval);
		if(retval < 0)
		{
			perror("--->client: sending failed\n");
			exit(1);
		}
		//printf("--->client: recieve retval:%d\n",retval);
		if((urlptr = strstr(sbuff,"/description")))
		{
			printf("--->client: recieve data:%s\n",sbuff);
			parsing_port(sbuff,urlptr);
			break;
		}
		printf("--->i val :%d\n",i);

	}
	retval = trivnet();
	retval = server();

}


