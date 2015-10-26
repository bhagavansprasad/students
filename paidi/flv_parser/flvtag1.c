/*header files*/
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<unistd.h>
# define swap_uint32(x) (((((x) & 0x000000FFU) << 24) | \
			(((x) & 0x0000FF00U) << 8)  | \
			(((x) & 0x00FF0000U) >> 8 ) | \
			(((x) & 0xFF000000U) >>24)))

/*function prototype*/
void position (char);
void get_previoustagsize(int);
void get_tagtype(char);
void get_datasize(char*);
void get_timestam(char*);
void get_timestampextended(char);
void get_streamID(char);
void get_compositiontime(char*);
void get_previoustagsize(int);
void get_tagtype(char);
void get_datasize(char*);
void get_timestamp(char*);
void get_timestampextended(char);
void get_streamID(char);
void get_previousetagsize(int);
/*flv_file header*/
typedef struct flv_header
{
	char name[3];
	char version;
	char flag;
	int  offset;
}flv_h;

/*header file metadata tag */

typedef struct flv
{
	int previoustagsize;
	char tagtype;
	char datasize[3];
	char timestamp[3];
	char timestampextended;
	char streamID;
}flv;

/*video tag header */
typedef struct video
{
	char frametype_codecID;
	char AVCpackettype;
	char compositiontime[3];
}flv_v;

/*  audio tag header */
typedef struct audio
{
	unsigned char soundformat_rate_size_type;
	char AACpackettype;
}flv_a;


main()
{
	flv_h l1;
	flv f1;
	flv_v s1;
	flv_a b1;
	int fd,i;

	fd=open("sixthsense.flv",O_RDONLY);
	read(fd,&l1.name,3);
	printf(" name= %s\n", l1.name);

	read(fd,&l1.version,1);
	printf(" version= %d\n", l1.version);

	read(fd,&l1.flag,1);
	printf(" flag= %d\n", l1.flag);

	read(fd,&l1.offset,4);
	i=swap_uint32(l1.offset);
	printf(" offset= %x\n", i);

	position(l1.flag);

	lseek(fd,9,SEEK_SET);
	printf("\n------>:flv metadata:<-------\n");
	read(fd,&f1.previoustagsize,4);
	printf(" previoustagsize= %d\n", f1.previoustagsize);

	read(fd,&f1.tagtype,1);
	get_tagtype(f1.tagtype);

	read(fd,&f1.datasize,3);
	get_datasize(f1.datasize);

	read(fd,&f1.timestamp,3);
	get_timestamp(f1.timestamp);

	read(fd,&f1.timestampextended,1);
	get_timestampextended(f1.timestampextended);

	read(fd,&f1.streamID,3); 
	int q;
	char *c;
	c=&f1.streamID;
	printf(" streamid= " );
	for(q=0;q<3;q++)
	{

		printf(" %x",f1.streamID);

	}	
	printf("\n");
	printf("\n");

	lseek(fd,843,SEEK_CUR);
	/*flv tag1 header*/
	printf("------>:flv tag1 header:<------\n");
	read(fd,&f1.previoustagsize,4); 
	get_previoustagsize(f1.previoustagsize);

	read(fd,&f1.tagtype,1);
	get_tagtype(f1.tagtype);

	read(fd,&f1.datasize,3);
	get_datasize(f1.datasize);

	read(fd,&f1.timestamp,3);
	get_timestamp(f1.timestamp);

	read(fd,&f1.timestampextended,1);
	get_timestampextended(f1.timestampextended);

	read(fd,&f1.streamID,3);
	printf(" streamID= %x", f1.streamID);

	/*video data read */ 
	printf("\n------>:video tag header:<--------\n");
	read(fd,&s1.frametype_codecID,1);
	printf(" frametype_codecID= %d", s1.frametype_codecID);

	read(fd,&s1.AVCpackettype,1);
	printf(" AVCpackettype= %d", s1.AVCpackettype);

	read(fd,&s1.compositiontime,3);
	get_compositiontime(s1.compositiontime);
	printf("\n");

	lseek(fd,38,SEEK_CUR);

	/*flv tag2 header*/

	printf("\n------->:flv tag2 header:<-------\n");
	read(fd,&f1.previoustagsize,4);
	get_previoustagsize(f1.previoustagsize); 

	read(fd,&f1.tagtype,1);
	get_tagtype(f1.tagtype);

	read(fd,&f1.datasize,3);
	get_datasize(f1.datasize);

	read(fd,&f1.timestamp,3);
	get_timestamp(f1.timestamp);

	read(fd,&f1.timestampextended,1);
	get_timestampextended(f1.timestampextended);

	read(fd,&f1.streamID,3);
	printf(" streamID= %d", f1.streamID);

	/*   audio tag header  */
	printf("\n------->:audio tag header:<----------\n");

	read(fd,&b1.soundformat_rate_size_type,1);
	printf(" soundformat_r_s_t= %d", b1.soundformat_rate_size_type);

	read(fd,&b1.AACpackettype,1);
	printf(" AACpackettype= %d", b1.AACpackettype);
	printf("\n");
}

void position (char k)
{
	int v=0;
	v=k&(1<<2);
	if(v==0)
	{
		printf(" flv tag header= no audio\n");
	}
	else
	{
		printf(" flv tag header = audio\n");
	}
	v=k&(1<<0);
	if(v==0)
	{
		printf(" flv tag header= no vedio");
	}
	else
	{
		printf(" flv tag header= vedio");
	}
}
void get_previoustagsize(int k)
{
	int i;
	i=swap_uint32(k);
	printf(" previoustagsize= %d\n", i);
}

void get_tagtype(char x)
{
	printf("<tagtype = %d", x);
}

void get_datasize(char *p)
{
	int s;
	char *c=&s;
	*(c+3)=0;
	*(c+2)=p[0];
	*(c+1)=p[1];
	*(c+0)=p[2];
	printf(" datasize= %d", s);
}
void get_timestamp(char *y)
{
	int b;
	char *d=&b;
	*(d+3)=0;
	*(d+2)=y[0];
	*(d+1)=y[1];
	*(d+0)=y[2];
	printf(" timestamp= %d", b);

} 
void get_timestampextended(char z)
{
	printf(" timestampextended =%d", z);
}

void get_compositiontime (char *n)
{
	int a;
	char *p=&a;
	*(p+3)=0;
	*(p+2)=n[0];
	*(p+1)=n[1];
	*(p+0)=n[2];
	printf(" compositiontime= %d", a);
}

