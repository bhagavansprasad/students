#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"string.h"
#include"unistd.h"
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int get_tag_value_by_tag_name(char *buff, char *needle, char schar, char echar, char *rbuff)
{
	char *t = strstr(buff, needle);
	int i = 0, j = 0;
	//printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != schar; i++);
		//printf("-->i :%d, t :%s\n", i, &t[i]);
		i++;
		for (j = 0 ; t[i] != echar; i++, j++)
			rbuff[j] = t[i];
		        rbuff[j] = '\0';
		//printf("-->j :%d, id_value :%s\n", i, rbuff);;
	}
}

int main()
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char buffer[]="hai aura network";
	char buff[500];
	int newfd;
	char id_value[20];
	char parent_id[20];
	char restricted[20];
	char title[100];
	char class[100];
	char protocolInfo[100];
	char size[20];
	char duration[20];
	char bitrate[20];
	char resolution[20];
	char sampleFrequency[20];
	char nrAudioChannels[20];
	char http[100];

	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(6666);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : Going for accepting connection \r\n");
	newfd = accept(socketfd,NULL,NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	printf("--->server : Got the connection request from client \r\n\n");

	read(newfd, buff, sizeof(buff));
	printf("--->buff read from socket:       %s\r\n",buff);

        printf("------------string parsing----------------\n");

        get_tag_value_by_tag_name(buff, "id=", '"', '"', id_value);
	get_tag_value_by_tag_name(buff, "parentID=", '"', '"', parent_id);
	get_tag_value_by_tag_name(buff, "restricted=", '"', '"', restricted);
	get_tag_value_by_tag_name(buff, "title", '>', '<', title);
	get_tag_value_by_tag_name(buff, "class", '>', '<', class);
	get_tag_value_by_tag_name(buff, "protocolInfo=", '"', '"',protocolInfo );
	get_tag_value_by_tag_name(buff, "size=", '"', '"',size);
	get_tag_value_by_tag_name(buff, "duration=", '"', '"',duration);
	get_tag_value_by_tag_name(buff, "bitrate=", '"', '"',bitrate);
	get_tag_value_by_tag_name(buff, "resolution=", '"', '"',resolution);
	get_tag_value_by_tag_name(buff, "sampleFrequency=", '"', '"',sampleFrequency);
	get_tag_value_by_tag_name(buff, "nrAudioChannels=", '"', '"',nrAudioChannels);
	get_tag_value_by_tag_name(buff, "http:", ' ', ' ',http);
    
	printf("-->id_value   :%s\n", id_value);
	printf("-->parent id  :%s\n", parent_id);
	printf("-->restricted :%s\n", restricted);
	printf("-->title      :%s\n", title);
	printf("-->class      :%s\n", class);
	printf("-->protocolInfo:%s\n", protocolInfo);
	printf("-->size:%s\n", size);
	printf("-->duration:%s\n", duration);
	printf("-->bitrate:%s\n", bitrate);
	printf("-->resolution:%s\n", resolution);
	printf("-->sampleFrequency:%s\n", sampleFrequency);
	printf("-->nrAudioChannels:%s\n", nrAudioChannels);
	printf("-->http:%s\n", http);

	write(newfd, buffer, sizeof(buffer));
	//write(newfd, buffer, strlen(buffer));
	shutdown(socketfd, SHUT_RDWR);

	close(socketfd);
	return 0;

}


