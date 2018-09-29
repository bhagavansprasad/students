#include <stdio.h>
#include <string.h>
  main()
  {
    char buffer[1024];
    char buff1[] = "<item id=\"218\" parentID=\"216\" restricted=\"1\">";
    char buff2[]="<dc:title>lifeisbeautiful.mp4</dc:title> <upnp:class>object.item.videoItem</upnp:class>";
    char buff3[]=" <res protocolInfo=\"http-get:*:video/mp4:*\" size=\"769757678\" duration=\"02:48:57.5\" bitrate=\"607\" resolution=\"624x272\" sampleFrequency=\"44100\" nrAudioChannels=\"1\"";
	char buff4[]=" http: //192.168.1.34:49152/content/media/object_id/217/res_id/0/ext/file.mp4</res> </item>";

    sprintf(buffer, "%s%s%s%s",buff1,buff2,buff3,buff4);
	printf("%s\n",buffer);
	//printf("-->buff len :%d\n", strlen(buff));
}
