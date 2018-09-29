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
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char buffer[1024];
	char buff[] = "<item id=\"218\" parentID=\"216\" restricted=\"1\"> <dc:title>lifeisbeautiful.mp4</dc:title> <upnp:class>object.item.videoItem</upnp:class> <res protocolInfo=\"http-get:*:video/mp4:*\" size=\"769757678\" duration=\"02:48:57.5\" bitrate=\"607\" resolution=\"624x272\" sampleFrequency=\"44100\" nrAudioChannels=\"1\"> http: //192.168.1.34:49152/content/media/object_id/217/res_id/0/ext/file.mp4</res> </item>";

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.1.0.0");
	myclientaddr.sin_port = htons(6666);

	printf("client : Connecting to the server\r\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}

	write(socketfd, buff, sizeof(buff));
	read(socketfd, buffer, sizeof(buffer));
	printf("string read from server:%s\r\n",buffer);

	close(socketfd);

	return 0;

}

