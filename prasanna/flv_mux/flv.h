typedef struct flvheader
{
	unsigned char signature[4];
	unsigned int version;
	unsigned int video;
	unsigned int audio;
	unsigned int dataoffset;
}flv_header;

typedef struct flvtags
{
	unsigned int filter;
	unsigned int tagtype;
	unsigned int datasize;
	unsigned int timestamp;
	unsigned int timestamp_extended;
	unsigned int streamID;
}flv_tag;
	
typedef struct scriptData
{
	unsigned int offset;	

}flv_scriptData;

typedef struct videotags
{
	unsigned int frame_type;
	unsigned int codec_ID;
	unsigned int AVCPacket_type;
	int composition_time;
	unsigned int video_tagBody;
	unsigned int offset;
}flv_video_tag;

typedef struct audiotags
{
	unsigned int soundType;
	unsigned int soundSize;
	unsigned int soundRate;
	unsigned int soundFormat;
	unsigned int AAC_packet_type;
	unsigned int offset;
}flv_audio_tag;
