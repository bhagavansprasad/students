/*header files*/
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<unistd.h>
#define audio 8
#define video 9
#define metadata 18
# define swap_uint32(x) (((((x) & 0x000000FFU) << 24) | \
		            	(((x) & 0x0000FF00U) << 8)  | \
		            	(((x) & 0x00FF0000U) >> 8 ) | \
		            	(((x) & 0xFF000000U) >>24)))

typedef struct flv_header
{
	 char name[4];
	 char version;
	 char flag;
	 int dataoffset;
}header;
typedef struct read_tag
{
	unsigned int previoustagsize;
	char tagtype;
	char datasize[3];
	char timestamp[3];
	char timestampextend;
	char streamid[3];
}tag;


typedef struct audio_tag
{
	unsigned char soundtypes;
	unsigned char AACpackettype;
}atag;

/* <function proto types > */
int read_header(int, header );
void read_tag(int ,tag );
int audio_tag(char);
void read_tagtype(int);
void get_audiotag(int,atag );
void get_datasize(int);
void get_timestamp(int);
void get_previoustagsize(int );
void get_soundtypes(unsigned char);
void get_dataoffset(int );
void get_aacpackettype(char);
void pass_info(int ,int , int );
