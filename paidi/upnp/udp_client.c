#include "udp.h"
#include "uconfig.h"
//#include <upnp_cds.h>

udp_contex_blk udp_cb;
main()
{
	int socketfd,port=0;
	int connected,sfd;
	struct sockaddr_in mysockaddr;
	char buff[1024];
	char sbuff[1024];
	char *urlptr;
	int i,retval=0,sd1_retval;
	char multicast_ip[100];
	socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}
	udp_cb.fd = socketfd;
	get_upnp_multicast_ip(multicast_ip);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = inet_addr(multicast_ip);
	mysockaddr.sin_port = htons(get_upnp_server_port());

	sd1_retval=sizeof(mysockaddr);

	printf("--->client: Connecting to the server\n");

	retval = sprintf(buff, "%sHOST: %sMAN: %s%s", M_SEARCH, MHOST, DISCOVER, MX_ST);

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
	//retval = trivnet();
	retval = server();
	retval = Browse_Metadata();
	retval = Browse_Direct_Children();
	retval = Browse_Data();
	retval = Browse_Data1();
//	retval = Browse_Directories();
//	retval = Browse_Directory_data();


//	sleep(5);

}


