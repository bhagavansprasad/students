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

