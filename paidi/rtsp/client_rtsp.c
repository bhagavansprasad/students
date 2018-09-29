#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include <string.h>

int main(void)
{
	int socketfd,read_retval,write_retval;
	int count  = 0;
	int connected;
	struct sockaddr_in myclientaddr;
	char reply[5000];
	char session_id[5000];
	int found_eoh = 0;
	char *a;

	char buff1[2000]="OPTIONS rtsp://192.168.1.34:8554/str RTSP/1.0\r\nCSeq: 64\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

	char buff2[2000]="DESCRIBE rtsp://192.168.1.34:8554/str RTSP/1.0\r\nCSeq: 65\r\nAccept: application/sdp\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

	char buff3[2000]="SETUP rtsp://192.168.1.34:8554/str/trackID=24 RTSP/1.0\r\nCSeq: 66\r\nTransport: RTP/AVP/TCP;unicast;interleaved=0-1\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n"; 

    char buff4[2000]="SETUP rtsp://192.168.1.34:8554/str/trackID=24 RTSP/1.0\r\nCSeq: 67\r\nTransport: RTP/AVP;unicast;client_port=57350-57351\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

	char buff5[2000] ="SETUP rtsp://192.168.1.34:8554/str/trackID=25 RTSP/1.0\r\nCSeq: 68\r\nTransport:RTP/AVP/TCP;unicast;interleaved=2-3\r\nSession: 8e5eebd2b88ec0fb\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n"; 
	char buff6[2000]="SETUP rtsp://192.168.1.34:8554/str/trackID=25 RTSP/1.0\r\nCSeq: 69\r\nTransport:RTP/AVP;unicast;client_port=34298-34299\r\nSession: 8e5eebd2b88ec0fb\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

    char buff[2000]="TEARDOWN rtsp://192.168.1.34:8554/str RTSP/1.0\r\n CSeq: 44\r\n Session: 2e82ff55541461f8\r\n User-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

	char buff7[2000]="PLAY rtsp://192.168.1.34:8554/str RTSP/1.0\r\nCSeq: 70\r\nSession: 9e4b6ce4b7038ad6\r\nRange: npt=0.000-\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

	   char buff8[2000]="GET_PARAMETER rtsp://192.168.1.32:8554/str RTSP/1.0\r\nCSeq: 71\r\nSession: 8e5eebd2b88ec0fb\r\nUser-Agent: LibVLC/1.1.13 (LIVE555 Streaming Media v2010.02.10)\r\n\r\n";

	 	
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.1.34");
	myclientaddr.sin_port = htons(8554);

	printf("client : Connecting to the server\r\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}



	printf("\n\r\rFIRST READ BUFFER\r\r\n");   
	write_retval = write(socketfd, buff1, strlen(buff1));
	read_retval=read(socketfd, buff1, sizeof(buff1));
	buff1[read_retval]='\0';
	printf("%s\n",buff1);

	printf("\n\r\rSECOND READ BUFFER\r\r\n");   
	write_retval = write(socketfd, buff2, strlen(buff2));
	while(1)
	{
		read_retval=read(socketfd, reply+count, 100);
		count = count + read_retval;
		a = strstr(reply, "\r\n\r\n");
		if (a && found_eoh == 0)
		{
			printf("-->Found End of reply 1 \n");
			found_eoh = 1;
			reply[count] = '\0';
			printf("\n%s\n",reply);
		}
		if ((found_eoh == 1) && (strstr(a+4,"\r\n") != NULL))
		{
			reply[count] = '\0';
			if (read_retval < 100)
			{
				printf("-->Found End of reply 2 \n");
				printf("%s\n",(a+4));
				break;
			}
		}
	}

    printf("THIRD READ BUFFER(SETUP) - REPLY UNSUPPORTED FORMAT\n");
	write_retval = write(socketfd, buff3, strlen(buff3));
	read_retval=read(socketfd, buff3, sizeof(buff3));
	buff3[read_retval]='\0';
	printf("%s\n",buff3);

	printf("FOURTH READ BUFFER(SETUP) - REPLY OK WITH SESSION ID\n");
	write_retval = write(socketfd, buff4, strlen(buff4));
	read_retval=read(socketfd, buff4, sizeof(buff4));
	buff4[read_retval]='\0';
	printf("%s\n",buff4);
	a = (strstr(buff4,"Session: "));
	int i;
	if(a)
	{
		for(i=0;i<=15;i++)
		{
			session_id[i]=(a+9)[i];
		}
		printf("session %s\n",session_id);

	}

	printf("FIFTH READ BUFFER(SETUP) - REPLY UNSUPPORTED FORMAT\n");
	a = (strstr(buff5,"Session: "));
	if(a)
	{
		for(i=0;i<=15;i++)
		{
			(a+9)[i] = session_id[i];
		}
	}
	write_retval = write(socketfd, buff5, strlen(buff5));
	printf("WR %d\n",write_retval);
	read_retval=read(socketfd, buff5, sizeof(buff5));
	buff5[read_retval] = '\0';
	printf("RR %d\n",read_retval);
	printf("%s\r\n",buff5);

	printf("SIXTHTH READ(SETUP) BUFFER - REPLY OK\n");
	a = (strstr(buff6,"Session: "));
	if(a)
	{
		for(i=0;i<=15;i++)
		{
			(a+9)[i] = session_id[i];
		}
	}
	write_retval = write(socketfd, buff6, strlen(buff6));
	read_retval=read(socketfd, buff6, sizeof(buff6));
	buff6[read_retval] = '\0';
	printf("%s\r\n",buff6);

	/*printf("\n\r\rZero READ BUFFER\r\r\n");   
	write_retval = write(socketfd, buff, strlen(buff));
	read_retval=read(socketfd, buff, sizeof(buff));
	buff[read_retval]='\0';
	printf("%s\n",buff);*/

	printf("SEVENTH READ(PLAY) BUFFER - REPLY OK\n");
	a = (strstr(buff7,"Session: "));
	if(a)
	{
		for(i=0;i<=15;i++)
		{
			(a+9)[i] = session_id[i];
		}
	}
	write_retval = write(socketfd, buff7, strlen(buff7));
	read_retval=read(socketfd, buff7, sizeof(buff7));
	buff7[read_retval] = '\0';
	printf("%s\r\n",buff7);

	printf("EIGHTH READ(GET_PARAMETER) BUFFER - REPLY OK\n");
	a = (strstr(buff8,"Session: "));
	if(a)
	{
		for(i=0;i<=15;i++)
		{
			(a+9)[i] = session_id[i];
		}
	}

	write_retval = write(socketfd, buff8, strlen(buff8));
	read_retval=read(socketfd, buff8, strlen(buff8));
	buff8[read_retval] = '\0';
	printf("%s\r\n",buff8);

	close(socketfd);

	return 0;

}

