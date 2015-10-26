#include<stdio.h>
#include"flv_a.h"

/*flv_headers*/

int read_header(int fd,header f1)
{
	if( read(fd,&f1.name,3)            != 3 ||
			read(fd,&f1.version,1)     != 1 ||
			read(fd,&f1.flag,1)        != 1 ||
			read(fd,&f1.dataoffset,4)  !=4 )
	{
		return 0;
	}

	if(f1.name[0]!= 'F' || f1.name[1] !='L' ||f1.name[2]!='V')
	{
		return 0;
	}

	if(f1.version!=1)
	{
		return 0;
	}
	if(audio_tag(f1.flag) && video_tag(f1.flag))
	{
		return 0;
	}
	if((swap_uint32(f1.dataoffset)) != 9)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

void read_tag(int fd,tag t)
{
	int p,k,val;
	short int u = 34;
	char *c = (char *)&p;
	char *r = (char *)&k;
	static int offset = 9;
	atag at;

	read(fd,&t.previoustagsize,4);
	read(fd,&t.tagtype,1);
	read(fd,&t.datasize,3);
	read(fd,&t.timestamp,3);
	read(fd,&t.timestampextend,1);
	read(fd,&t.streamid,3);

	val = swap_uint32(t.previoustagsize);

	*(c+3)=0;
	*(c+2)=t.timestamp[0];
	*(c+1)=t.timestamp[1];
	*(c+0)=t.timestamp[2];

	*(r+3)=0;
	*(r+2)=t.datasize[0];
	*(r+1)=t.datasize[1];
	*(r+0)=t.datasize[2];

	offset+=(sizeof(t.previoustagsize))+val;

	switch(t.tagtype)
	{
		case metadata :
			printf(" ");
			lseek(fd,k,SEEK_CUR);
			break;
		case video:
			lseek(fd,k,SEEK_CUR);
			break;
		case audio:
			printf("<tag type = audio ");
			pass_info(k,p,offset);
			get_audiotag(fd,at);
			lseek(fd,(k-2),SEEK_CUR);
			break;

		default :printf("no tags\n");
	}

}





void get_audiotag(int fd, atag at)
{
	read(fd,&at.soundtypes,1);
	read(fd,&at.AACpackettype,1 );
	get_soundtypes(at.soundtypes);
	//  get_aacpackettype(at.AACpackettype);
}
main()
{
	int fd,i,r;
	header f1;
	tag t;


	fd= open ("sixthsense.flv",O_RDONLY);
	if(fd==-1)
	{
		perror("File is not opened\n");
		exit(0);
	}
	read_header(fd,f1);
	

	for( ; ; )
	{

          read_tag(fd,t);
	}

	close(fd);
}


