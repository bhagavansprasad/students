/* Flv header */
typedef struct header 
{
	unsigned char signature[3];
	unsigned char version;
	unsigned char flag;
	unsigned int byte_off_set;
}flv_header;

typedef struct body
{
	unsigned int previous_tag;
	unsigned char type;             //It determines the layout of body forexample{audio,video,metadata}
	unsigned char data_size[3];   //It tells size of body(total size - 11)
	unsigned char time_stamp[3];     //It tells Timestamp of tag in Milliseconds
	unsigned char time_stamp_extended; //Extension of timestamp
	unsigned char stream_id[3];
	}flv_tag;

typedef struct video
{
unsigned char frame_codec;
unsigned char avc_packet_type;
signed char composition_time[4];
}flv_video;


typedef struct audio
{
unsigned char sound;
unsigned char aac_packet_type;
}flv_audio;

/*MACRO*/
# define swap_uint32(x) (((((x) & 0x000000FFU) << 24) | \
    (((x) & 0x0000FF00U) << 8)  | \
    (((x) & 0x00FF0000U) >> 8)  | \
    (((x) & 0xFF000000U) >> 24)))


/*prototype */
void write_header(int fd,int fd1,flv_header hd);
int write_tag(int fd,int fd1,flv_tag tag);
void check_tag_type(int fd,unsigned char tagg,unsigned int previous_tag,int audio_fd,int video_fd);


