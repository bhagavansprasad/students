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

typedef struct vedio_tag
{
	char frametype;
	char codecID;
	char AVCpackettype;
	unsigned char compositiontime[3];
}vtag;

/* <function proto types > */
int read_header(int, header );
void read_tag(int ,tag );
int video_tag(char);
void read_tagtype(int);
void get_videotag(int,vtag );
void get_video_frame();
void get_datasize(int);
void get_timestamp(int);
void get_avcpacket_type(char);
void get_previoustagsize(int );
void get_dataoffset(int );
void get_codecID(char);
void get_compositiontime(unsigned char );
void get_aacpackettype(char);
void get_video_timestamp(int );
void pass_info(int ,int , int );
