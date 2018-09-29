#include "define.h"
int main()
{
	int fd=-1,v_fd=-1;
	flv_body body;

	fd = open("sixth.flv",O_RDONLY);
	if(fd == -1)
	{
		perror("file opened failed\n");
		return 0;
	}
	v_fd = creat("video.flv",O_CREAT|O_WRONLY|O_TRUNC);
	if(v_fd == -1)
	{
		perror("file opened failed\n");
		return 0;
	}

	video(fd,v_fd);

}
int video(int fd,int v_fd)
{
	flv_video video;
	int i,p,n,m,k,w,codecID,frametype,offset;
	char ub=0;
	flv_body body;
	printf("---------->datasize<------------\n");
	read(fd,&body.datasize,3);
	showbits(body.datasize,24);
	write(v_fd,&body.datasize,3);
	showbits(body.datasize,24);

	int v_datasize=(((body.datasize[0]<<24)>>8)+((body.datasize[1]<<24)>>16)+body.datasize[2]);
	showbits(v_datasize,24);
	printf("---------->timestamp<------------\n");
	
	read(fd,&body.timestamp,3);
	showbits(body.timestamp,24);
	write(v_fd,&body.timestamp,3);
	showbits(body.timestamp,24);
	int v_timestamp=(((body.timestamp[0]<<24)>>8)+((body.timestamp[1]<<24)>>16)+body.timestamp[2]);
	showbits(body.timestamp,24);
	//printf("timestamp=\"%d\" ",v_timestamp);
	//printf("datasize=\"%d\" >\n",v_datasize);
	
	printf("---------->time stamp extended<------------\n");
	read(fd,&body.timestampextended,1);
	showbits(body.timestampextended,8);
	write(v_fd,&body.timestampextended,1);
	showbits(body.timestampextended,8);
	printf("---------->streamID<------------\n");
	read(fd,&body.streamID,3);
	showbits(body.streamID,24);
	write(v_fd,&body.streamID,3);
	showbits(body.streamID,24);
	int v_streamid=(((body.streamID[0]<<24)>>8)+((body.streamID[1]<<24)>>16)+body.streamID[2]);
	showbits(body.streamID,24);
	
	printf("---------->frametype<------------\n");
	read(fd,&video.frametype,1);
	showbits(video.frametype,8);
	write(v_fd,&video.frametype,1);
	showbits(video.frametype,8);

	ub = video.frametype;
	int temp= ub;
	ub = ub <<4;
	ub = ub >>4;
	int fb = temp;
	fb = fb>>4;
	frametype = fb;
	showbits(frametype,4);
	codecID = ub;
	showbits(codecID,4);
	switch(codecID)
	{
		case 2:printf("<videodata codecID=\"sorenson H.263\" ");break;
		case 3:printf("<videodata codecID=\"screen video\" ");break;
		case 4:printf("<videodata codecID=\"on2 VP6\" ");break;
		case 5:printf("<videodata codecID=\"on2 VP6 with alpha channel\" ");break;
		case 6:printf("<videodata codecID=\"screen video version2\" ");break;
		case 7:printf("<videodata codecID=\"AVC\" ");break;
	}
	switch(frametype)
	{
		case 1:printf("frametype=\"keyframe\" />\n</tag>");break;
		case 2:printf("frametype=\"interframe\" />\n</tag>");break;
		case 3:printf("frametype=\"disposable inter frame\" />\n</tag>");break;
		case 4:printf("frametype=\"generated frame\" />\n</tag>");break;
		case 5:printf("frametype=\"video info/command frame\" />\n</tag>");break;
	}
	if(codecID == 7 && frametype == 5)
	{
		offset = lseek(fd,(v_datasize-6),SEEK_CUR);
	}
	else
	{
		if(codecID == 7)
		{
			read(fd,&video.AVCpackettype,1);
			showbits(video.AVCpackettype,8);
			write(v_fd,&video.AVCpackettype,1);
			showbits(video.AVCpackettype,8);
			read(fd,&video.compositiontime,3);
			showbits(video.compositiontime,24);
			write(v_fd,&video.compositiontime,3);
			showbits(video.compositiontime,24);
			offset = lseek(fd,v_datasize-5,SEEK_CUR);
		}
		if(frametype == 5)
		{
			read(fd,&video.videotagbody,1);
			showbits(video.videotagbody,8);
			write(v_fd,&video.videotagbody,1);
			showbits(video.videotagbody,8);
			offset = lseek(fd,v_datasize-2,SEEK_CUR);
		}
		if(codecID != 7 && frametype != 5)
		{
			offset = lseek(fd,v_datasize-1,SEEK_CUR);
		}
	}
	return 0;
}
int showbits(int n,int size)
{
	int i;
	for(i=(size-1);i>=0;i--)
	{
		if(n & (1<<i))
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	printf("\n");
}
