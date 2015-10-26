
typedef struct flvheader
{
	unsigned char signature[4];
	unsigned int version;
	unsigned int audio;
	unsigned int video;
	unsigned int offset;
}flv_header;
typedef struct flvtags
{
	unsigned int Filter;
	unsigned int TagType;
	unsigned int DataSize;
	unsigned int Timestamp;
	unsigned int TimestampExtended;
	unsigned int StreamID;
}flv_tags;

typedef struct scriptdada
{
	unsigned int Offset;
}flv_scriptdata;

typedef struct flvvideo
{
	unsigned int FrameType;
	unsigned int CodecID;
	unsigned int AVCPacketType;
	int CompositionTime;
	unsigned VideoTagBody;
	unsigned int Offset;
}flv_videotag;
typedef struct flvaudio
{
	unsigned int SoundFormat;
	unsigned int SoundRate;
	unsigned int SoundSize;
	unsigned int SoundType;
	unsigned int AACPacketType;
	unsigned int Offset;
}flv_audiotag;

