typedef struct flv_header_t
{
	unsigned char sign[4];
	int version;
	int reserved1;
	int is_audio;
	int reserved2;
	int is_video;
	unsigned offset;
}flv_header;
typedef struct flv_body_t
{
	int tag_size;
	int tag_type;
	int filter;
	int reserved;
	int data_size;
	int time_stamp;
	int timest_ext;
	int streamId;
}flv_body;
typedef struct flv_audio_t
{
	int atag_size;
	int sound_format;
	int sound_rate;
	int sound_size;
	int sound_type;
	int aacpacket_type;
	unsigned offset;
}flv_audio;
typedef struct flv_video_t
{
	int vtag_size;	
	int frametype;
	int codecId;
	int avcpackettype;
	unsigned offset;
}flv_video;


