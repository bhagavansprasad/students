#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"

int main(void)
{
	int retval=0,len = 50 , l=0;
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char buff[]="The Transmission Control Protocol provides a communication service at an intermediate level between an application used";
//	char buff[]="ISO0150000500110323A800128A18018650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000006 1234P0399904ABCD";
//	char buff[]="ISO0150000500200B23A800128A180180000000014000000650000000000002050042813271000057813271004280428042803456174591700012340000=000000230579A1B2C3D4E5SOLABTEST TEST-3 DF MX010abcdefghij484012B456PRO1+000006 1234P0399904ABCD";
	char read_buff[1024];
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.1.34");
	myclientaddr.sin_port = htons(7777);

	printf("client : Connecting to the server\r\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}
	while(1)
	{
		retval = write(socketfd, buff+l, len);
		//buff=buff+retval;
		l = l+retval;

		printf("-->C. w.retval :%d\n", retval);
		printf("-->C. sizeof buff is  :%d\n", sizeof(buff));
		printf("-->C. l+retval is  :%d\n", l);

		//retval = read(socketfd, read_buff, sizeof(read_buff));
		if(l > sizeof(buff))
		{
			printf("-->C. r.retval :%d\n", retval);
			break;
		}
		printf("string read from server:%s\n",read_buff);
		sleep(1);
	}
	close(socketfd);

	return 0;

}

