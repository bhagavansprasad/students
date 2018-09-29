#include "define.h"
main()
{
	int fd = -1;
	flv_audio audio;
	flv_video video;
	fd = open("sixth.flv",O_RDONLY);
	if(fd == -1)
	{
		perror("file opened failed\n");
		return 0;
	}
	read_head(fd);
	read_body(fd);
	while(1)
	{
		int retval=read_tagtype(fd);
		switch(retval)
		{
			case 8: read_audio(fd);
					break;
			case 9:	read_video(fd);
					break;
			case 18: read_script(fd);
					 break;
		}
	}
}
int read_head(int fd)
{
	int i;
	int n,p,m;
	flv_header head;
	read(fd, &head.signature, 4);
	printf("signature:%c %c %c\n",head.signature[0],head.signature[1],head.signature[2]);
	printf("version:%d\n", head.version);

	read(fd, &head.flag_reserved, 1);
	printf("flagreserved:%d\n",head.flag_reserved);
	printf("audio:%d\n",(head.flag_reserved&(1<<0)));
	printf("video:%d\n",(head.flag_reserved&((1<<2)>>2)));
	//showbits(head.flag_reserved,8);

	read(fd,&head.data_offset,4);
	n=head.data_offset;
	//printf("data_offset:%d\n",*((char*)(p+3)));
	p=((((n>>24)|(n<<24)))|((((n<<16)>>24)<<16)|(((n>>16)<<24)>>16)));
	printf("data_offset:%d\n",p);
}	
int read_body(int fd)
{
	int i;
	int n,p,m;
	flv_body body;

	read(fd,&body.previoustag,4);
	printf("previoustag:%d\n",body.previoustag);

	read(fd,&body.tagtype,1);
	printf("tagtype:%d\n",body.tagtype);

	read(fd,&body.datasize,3);
	printf("datasize:%x %x %x\n",body.datasize[0],body.datasize[1],body.datasize[2]);
	m=((body.datasize[0]<<24)>>8) | ((body.datasize[1]<<24)>>16) | ((body.datasize[2]<<24)>>24);
	printf("datasize:%d\n",m);

	read(fd,&body.timestamp,3);
	//printf("timestamp:%d %d %d\n",body.timestamp[0],body.timestamp[1],body.timestamp[2]);
	int tmp=((body.timestamp[0]<<24)>>8)|((body.timestamp[1]<<24)>>16)|((body.timestamp[2]<<24)>>24);
	printf("timestamp:%d\n",tmp);

	read(fd,&body.timestampextended,1);
	printf("timestampextended:%d\n",body.timestampextended);

	read(fd,&body.streamID,3);
	printf("streamID:%d\n",body.streamID);
	int retval=lseek(fd,843,SEEK_CUR);
	printf("retval:%d\n",retval);
}
int read_audio(int fd)
{
	flv_audio audio;
	int n;
	read(fd,&audio.soundformat,1);
	n=audio.soundformat;
	printf("sound format:%d\n",audio.soundformat);
}
int read_video(int fd)
{
	flv_video video;
	read(fd,&video.frametype,1);
	printf("frametype:%d\n",video.frametype);
}
int  showbits(int n,int size)
{
	int i;
	for(i=7;i>=0;i--)
	{
		if(n & (1<<i))
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	return 0;	
}
