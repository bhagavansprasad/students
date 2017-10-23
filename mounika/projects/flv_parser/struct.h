#include <stdbool.h>
struct student 
{
	int num;
	char name[10];
};

struct video
{
	int  frametype;
	int  codecid;
	int AVCpackettype;
	int comp_time;
}v;

struct audio
{
	char soundformat;
	char soundrate;
	char soundsize;
	char soundtype;
	char AACpackettype;
}a;

struct employee
{
	int id;
	char name[10];
};

struct flv_header
{
	char name[4];
	char ver;
	char res;
	int data;
	int video_bit;
	int audio_bit;
}s1;

struct tag_h
{
	char res;
	char filter;
	char time_stamp_ex;
	int  tag_type;
	int data_size;
	int time_stamp;
	int stream_id;
	int prev_tag;
}b;
