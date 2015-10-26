#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include <string.h>
#include <fcntl.h>
typedef struct 
{
	char signature[3];
	char version;
	unsigned char flag_reserved;
	int data_offset;
}flv_header;
typedef struct 
{
	unsigned int previoustag;
	unsigned char tagtype;
	unsigned char datasize[3];
	unsigned char timestamp[3];
	unsigned char timestampextended;
	unsigned char streamID[3];
}flv_body;
typedef struct 
{
	unsigned char soundformat;
	unsigned char AACpackettype;
}flv_audio;
typedef struct
{
	unsigned char frametype;
	unsigned char AVCpackettype;
	unsigned char compositiontime[3];
	unsigned char videotagbody;
}flv_video;
typedef struct 
{
	unsigned char scriptdata;
}flv_script;

