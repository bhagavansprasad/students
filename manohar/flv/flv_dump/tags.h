int header(int fd,int v_fd,int a_fd)
{
	flv_header head;
	read(fd, &head.signature, 4);
	printf("signature:%c %c %c\n",head.signature[0],head.signature[1],head.signature[2]);
//	write(v_fd,&head.signature,4);
//	write(a_fd,&head.signature,4);
	printf("version:%d\n", head.version);
	read(fd, &head.flag_reserved, 1);
	write(v_fd,&head.flag_reserved,1);
	write(a_fd,&head.flag_reserved,1);
	printf("flagreserved:%d\n",head.flag_reserved);
	printf("audio:%d\n",(head.flag_reserved&(1<<0)));
	printf("video:%d\n",(head.flag_reserved&((1<<2)>>2)));
	read(fd,&head.data_offset,4);
	write(v_fd,&head.data_offset,4);
	write(a_fd,&head.data_offset,4);
	int n=head.data_offset;
	int p=((((n>>24)|(n<<24)))|((((n<<16)>>24)<<16)|(((n>>16)<<24)>>16)));
	printf("data_offset:%d\n",p);
}
int scriptdata(int fd,int v_fd,int a_fd)
{
	flv_script script;
	int i,ub=0,p,n,m,k,w;
	flv_body body;
	read(fd,&body.datasize,3);
	write(v_fd,&body.datasize,3);
	write(a_fd,&body.datasize,3);
	int	f_datasize=(((body.datasize[0]<<24)>>8)+((body.datasize[1]<<24)>>16)+body.datasize[2]);
	
	read(fd,&body.timestamp,3);
	write(v_fd,&body.timestamp,3);
	write(a_fd,&body.timestamp,3);

	int f_timestamp=(((body.timestamp[0]<<24)>>8)+((body.timestamp[1]<<24)>>16)+body.timestamp[2]);
	printf("timestamp=\"%d\" ",f_timestamp);
	printf("datasize=\"%d\" >",f_datasize);
	read(fd,&body.timestampextended,1);
	write(v_fd,&body.timestampextended,1);
	write(a_fd,&body.timestampextended,1);
	read(fd,&body.streamID,3);
	write(v_fd,&body.streamID,3);
	write(a_fd,&body.streamID,3);
	int f_streamid=(((body.streamID[0]<<24)>>8)+((body.streamID[1]<<24)>>16)+body.streamID[2]);
	int offset=lseek(fd,f_datasize,SEEK_CUR);
	return f_datasize;
}
int video(int fd,int v_fd)
{
	flv_video video;
	int i,p,n,m,k,w,codecID,frametype,offset;
	char ub=0;
	flv_body body;
	read(fd,&body.datasize,3);
	write(v_fd,&body.datasize,3);

	int v_datasize=(((body.datasize[0]<<24)>>8)+((body.datasize[1]<<24)>>16)+body.datasize[2]);
	read(fd,&body.timestamp,3);
	write(v_fd,&body.timestamp,3);
	int v_timestamp=(((body.timestamp[0]<<24)>>8)+((body.timestamp[1]<<24)>>16)+body.timestamp[2]);
	printf("timestamp=\"%d\" ",v_timestamp);
	printf("datasize=\"%d\" >\n",v_datasize);
	read(fd,&body.timestampextended,1);
	write(v_fd,&body.timestampextended,1);
	read(fd,&body.streamID,3);
	write(v_fd,&body.streamID,3);
	int v_streamid=(((body.streamID[0]<<24)>>8)+((body.streamID[1]<<24)>>16)+body.streamID[2]);
	read(fd,&video.frametype,1);
	write(v_fd,&video.frametype,1);

	ub = video.frametype;
	int temp= ub;
	ub = ub <<4;
	ub = ub >>4;
	int fb = temp;
	fb = fb>>4;
	frametype = fb;
	codecID = ub;
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
			write(v_fd,&video.AVCpackettype,1);
			read(fd,&video.compositiontime,3);
			write(v_fd,&video.compositiontime,3);
			offset = lseek(fd,v_datasize-5,SEEK_CUR);
		}
		if(frametype == 5)
		{
			read(fd,&video.videotagbody,1);
			write(v_fd,&video.videotagbody,1);
			offset = lseek(fd,v_datasize-2,SEEK_CUR);
		}
		if(codecID != 7 && frametype != 5)
		{
			offset = lseek(fd,v_datasize-1,SEEK_CUR);
		}
	}
	return v_datasize;
}

int audio(int fd,int a_fd)
{
	flv_audio audio;
	flv_body body;

	int i,ub=0,temp,offset,a_streamid,a_timestamp,a_datasize,soundformat,soundrate,soundSize,soundType;

	read(fd,&body.datasize,3);
	a_datasize=(((body.datasize[0]<<24)>>8)+((body.datasize[1]<<24)>>16)+body.datasize[2]);
	read(fd,&body.timestamp,3);
	a_timestamp=(((body.timestamp[0]<<24)>>8)+((body.timestamp[1]<<24)>>16)+body.timestamp[2]);
	printf("timestamp=\"%d\" ",a_timestamp);
	printf("datasize=\"%d\" >\n",a_datasize);
	read(fd,&body.timestampextended,1);
	read(fd,&body.streamID,3);
	a_streamid=(((body.streamID[0]<<24)>>8)+((body.streamID[1]<<24)>>16)+body.streamID[2]);

	read(fd,&audio.soundformat,1);
	ub = audio.soundformat;
	soundformat=ub>>4;
	soundrate=(ub&12)>>2;
	soundSize=(ub&2)>>1;
	soundType=(ub&2)>>1;

	switch(soundType)	
	{
		case 0:printf("<audioData type=\"Mono\" ");break;
		case 1:printf("<audioData type=\"stereo\" ");break;
	}
	switch(soundSize)
	{
		case 0:printf("size=\"8\" ");break;
		case 1:printf("size=\"16\" ");break;
	}
	switch(soundrate)
	{
		case 0:printf("rate=\"5.5\" ");break;
		case 1:printf("rate=\"11\" ");break;
		case 2:printf("rate=\"22\" ");break;
		case 3:printf("rate=\"44\" ");break;
	}
	switch(soundformat)
	{
		case 0:printf("format=\"Linear PCM,platform endian\" />\n</tag>");break;
		case 1:printf("format=\"ADPCM\" />\n</tag>");break;
		case 2:printf("format=\"MP3\" />\n</tag>");break;
		case 3:printf("format=\"Linear PCM,little endian\" />\n</tag>");break;
		case 4:printf("format=\"Nellymoser 16 kHz mono\" />\n</tag>");break;
		case 5:printf("format=\"Nellymoser 8 kHz mono\" />\n</tag>");break;
		case 6:printf("format=\"nellymoser\" />\n</tag>");break;
		case 7:printf("format=\"G.711 A-Law logarithmic PCM\" />\n</tag>");break;
		case 8:printf("format=\"G.711 mu-Law logarithmic PCM\" />\n</tag>");break;
		case 9:printf("format=\"reserved\" />\n</tag>");break;
		case 10:printf("format=\"AAC\" />\n</tag>");break;
		case 11:printf("format=\"Speex\" />\n</tag>");break;
		case 14:printf("format=\"MP3 8 kHz\" />\n</tag>");break;
		case 15:printf("format=\"Device-specific sound\" />\n</tag>");break;
	}
	if(soundformat==10)
	{
		read(fd,&audio.AACpackettype,1);
		offset = lseek(fd,(a_datasize-2),SEEK_CUR);
	}
	else
	{
		offset = lseek(fd,(a_datasize-1),SEEK_CUR);
	}
	return offset;
}


