#include "stdbool.h"

struct student 
{
	int num;
	char name[10];
};

struct flv_header
{
	char sign[3];
	int version;
	char res;
	int audio_bit;
	int vedio_bit;
	unsigned int data_offset;
}hdata;

struct flv_tags
{
	int previoustag;
	char reserved;
	char filter;
	char tag_type;
	char timestamp_extended;
	int data_size;
	int timestamp;
	int stream_id;
}tdata;

struct flv_audio_header
{
	int soundformat;
	char soundrate;
	char soundsize;
	char soundtype;
	char aacpackettype;
}adata;

struct flv_audio_body
{
	int sounddata;
}abdata;

struct flv_video_header
{
	int frame_type;
	int codecID;
	int AVCpackettype;
	int compositiontime;
}vdata;

