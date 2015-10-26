
typedef struct read_header
{
	 char name[4];
	 char version;
	 char flags;
	 int offset;
}header;
typedef struct read_metadata
{
	unsigned int pr_tagsize;
	char tagtype;
	char datasize[3];
	char timestamp[3];
	char timestampextend;
	char streamid[3];
}metadata;

typedef struct vedio_tag
{
	char frametype;
	char AVCpackettype;
	signed int compositiontime;
}tag;

typedef struct audio_tag
{
	unsigned char soundtypes;
	unsigned char AACpackettype;
}tag;

/* <function proto types > */
void read_header(int);
void read_tagtype(int);
void get_videotag(int );
void get_audtag(int );
void get_video_frame();
//void get_data_offset(int );
//void get_flags(char);
void get_datasize(int);
void get_timestamp(int);
void get_frametype(char);
void get_avcpacket_type(char);
//void get_compositiontime(signed int );
void get_previoustagsize(int );
void get_soundtypes(unsigned char);
void get_dataoffset(int );



