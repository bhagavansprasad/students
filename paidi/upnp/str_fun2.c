#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
char buff[] = "<item id=\"218\" parentID=\"216\" restricted=\"1\"> <dc:title>lifeisbeautiful.mp4</dc:title> <upnp:class>object.item.videoItem</upnp:class> <res protocolInfo=\"http-get:*:video/mp4:*\" size=\"769757678\" duration=\"02:48:57.5\" bitrate=\"607\" resolution=\"624x272\" sampleFrequency=\"44100\" nrAudioChannels=\"1\"> http: //192.168.1.34:49152/content/media/object_id/217/res_id/0/ext/file.mp4</res> </item>";


int get_tag_value_by_tag_name(char *buff, char *needle, char schar, char echar, char *rbuff)
{
	char *t = strstr(buff, needle);
	int i = 0, j = 0;

	//printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != schar; i++);
		//	printf("-->i :%d, t :%s\n", i, &t[i]);

		i++;
		for (j = 0 ; t[i] != echar; i++, j++)
			rbuff[j] = t[i];

		rbuff[j] = '\0';

		//printf("-->j :%d, id_value :%s\n", i, rbuff);;
	}
}


main()
{
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

	get_tag_value_by_tag_name(buff, "id=", '"', '"', id_value);
	//id = atoi(id_value);
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

}
