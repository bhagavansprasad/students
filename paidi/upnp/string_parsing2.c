#include <stdio.h>
#include <string.h>
main()
{
	int i=0;
	char temp[500];
	char *ptr;
char buff[]= "<item id=\"218\" parentID=\"216\" restricted=\"1\"><dc:title>lifeisbeautiful.mp4</dc:title><upnp:class>object.item.videoItem</upnp:class> <res protocolInfo=\"http-get:*:video/mp4:*\"size=\"769757678\" duration=\"02:48:57.5\" bitrate=\"607\"resolution=\"624x272\"sampleFrequency=\"44100\" nrAudioChannels=\"1\"url\"http://192.168.1.34:49152/content/media/object_id/217/res_id/0/ext/file.mp4\" </res> </item> ";
ptr=buff;
	ptr=strstr(buff,"item id");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("item id =%d\n",i);
    i=0;
	
	ptr=strstr(buff,"parentID");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("parentID =%d\n",i);
	i=0;

	
	ptr=strstr(buff,"restricted");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("restricted =%d\n",i);
    i=0;

	ptr=strstr(buff,"dc:title");
	for(;*ptr++!='>';);
	for(;*ptr!='<';ptr++)
	{
		temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("title =%s\n",temp);
	i=0;

    ptr=strstr(buff,"upnp:class");
	for(;*ptr++!='>';);
	for(;*ptr!='<';ptr++)
	{
		temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("class =%s\n",temp);
	i=0;

    ptr=strstr(buff,"res protocolInfo");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("protocol =%s\n",temp);
	i=0;

    ptr=strstr(buff,"size");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("size =%d\n",i);
    i=0;
    
	ptr=strstr(buff,"duration");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("duration =%d\n",i);
    i=0;

	ptr=strstr(buff," bitrate");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf(" bitrate =%d\n",i);
    i=0;


    ptr=strstr(buff,"resolution");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("resolution =%d\n",i);
    i=0;
 
    ptr=strstr(buff,"sampleFrequency");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("sampleFrequency =%d\n",i);
    i=0;

    ptr=strstr(buff,"nrAudioChannels");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		i=i*10+(*ptr-48);
	}
	printf("nrAudioChannels =%d\n",i);
    i=0;

    ptr=strstr(buff,"url");
	for(;*ptr++!='"';);
	for(;*ptr!='"';ptr++)
	{
		temp[i++]=*ptr;
	}
	temp[i]='\0';
	printf("url =%s\n",temp);
	i=0;


    
}
