
#define INPUT_FILE_PATH    "t.flv"
#define OUTPUT_VIDEO_ES_PATH "v.h264"
#define OUTPUT_AUDIO_ES_PATH "a.aac"
#define OUTPUT_DTS_PATH	  "dts.txt"
#define OUTPUT_ALLDATA "samp.flv"
#define FLV_AUDIO_TAG_SOUND_TYPE_MONO    0
#define FLV_AUDIO_TAG_SOUND_TYPE_STEREO  1

#define FLV_AUDIO_TAG_SOUND_SIZE_8       0
#define FLV_AUDIO_TAG_SOUND_SIZE_16      1

#define FLV_AUDIO_TAG_SOUND_RATE_5_5     0
#define FLV_AUDIO_TAG_SOUND_RATE_11      1
#define FLV_AUDIO_TAG_SOUND_RATE_22      2
#define FLV_AUDIO_TAG_SOUND_RATE_44      3

#define FLV_AUDIO_TAG_SOUND_FORMAT_LINEAR_PCM          0
#define FLV_AUDIO_TAG_SOUND_FORMAT_ADPCM               1
#define FLV_AUDIO_TAG_SOUND_FORMAT_MP3                 2
#define FLV_AUDIO_TAG_SOUND_FORMAT_LINEAR_PCM_LE       3
#define FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER_16_MONO  4
#define FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER_8_MONO   5
#define FLV_AUDIO_TAG_SOUND_FORMAT_NELLYMOSER          6
#define FLV_AUDIO_TAG_SOUND_FORMAT_G711_A              7
#define FLV_AUDIO_TAG_SOUND_FORMAT_G711_MU             8
#define FLV_AUDIO_TAG_SOUND_FORMAT_RESERVED            9
#define FLV_AUDIO_TAG_SOUND_FORMAT_AAC                 10
#define FLV_AUDIO_TAG_SOUND_FORMAT_SPEEX               11
#define FLV_AUDIO_TAG_SOUND_FORMAT_MP3_8               14
#define FLV_AUDIO_TAG_SOUND_FORMAT_DEVICE_SPECIFIC     15

/* video tag */
#define FLV_VIDEO_TAG_CODEC_JPEG            1
#define FLV_VIDEO_TAG_CODEC_SORENSEN_H263   2
#define FLV_VIDEO_TAG_CODEC_SCREEN_VIDEO    3
#define FLV_VIDEO_TAG_CODEC_ON2_VP6         4
#define FLV_VIDEO_TAG_CODEC_ON2_VP6_ALPHA   5
#define FLV_VIDEO_TAG_CODEC_SCREEN_VIDEO_V2 6
#define FLV_VIDEO_TAG_CODEC_AVC             7

#define FLV_VIDEO_TAG_FRAME_TYPE_KEYFRAME               1
#define FLV_VIDEO_TAG_FRAME_TYPE_INTERFRAME             2
#define FLV_VIDEO_TAG_FRAME_TYPE_DISPOSABLE_INTERFRAME  3
#define FLV_VIDEO_TAG_FRAME_TYPE_GENERATED_KEYFRAME     4
#define FLV_VIDEO_TAG_FRAME_TYPE_COMMAND_FRAME          5


#define FLV_HAS_VIDEO 0x01
#define FLV_HAS_AUDIO 0x04

#define TAG_HEADER_SIZE		11
#define FLV_TAGTYPE_VIDEO	9
#define FLV_TAGTYPE_AUDIO	8
#define FLV_TAGTYPE_SCRIPT  18

// Originally from SorensonSupport.h
#define VIDEO_CODEC_MASK		0x0F
#define VIDEO_CODEC_JPEG		0x01	// currently unused
#define VIDEO_CODEC_SORENSON	0x02
#define VIDEO_CODEC_HOMEBREW	0x03	// currently unused
#define VIDEO_CODEC_VP6			0x04
#define VIDEO_CODEC_VP6ALPHA	0x05	// currently unused
#define VIDEO_CODEC_DEVICEVIDEO	0x06
#define VIDEO_CODEC_H264		0x07
#define AUDIO_ONLY_CODEC		0x10

#define FRAME_TYPE_MASK			0xF0
#define FRAME_TYPE_KEY			0x10
#define FRAME_TYPE_I			0x20
#define FRAME_TYPE_D			0x30

#define AAC_AUD_OBJ_TYPE_MSK	0xF8
#define AAC_AUD_SMPL_FREQ_INDEX_MSK 0x0780
#define AAC_AUD_CHNL_CFG_MSK 0x0078
#define AAC_AUD_OBJ_TYPE_EXT_MSK 0x07E0

#define FLV_SCRIPT_NUMBER	 0
#define FLV_SCRIPT_BOOL		 1
#define FLV_SCRIPT_STRING	 2
#define FLV_SCRIPT_OBJECT	 3

#define MAX_STACK_BUFF (512*1024)
typedef struct __flv_header {
    byte            signature[3]; /* always "FLV" */
    uint8           version; /* should be 1 */
    uint8_bitmask   flags;
    uint32_be       offset; /* always 9 */
} flv_header;

typedef struct __flv_tag {
	uint32_be  previous_tag_size;
    uint8       type;
    unsigned int   body_length; /* in bytes, total tag size minus 11 */
    unsigned int    timestamp; /* milli-seconds */
    uint8       timestamp_extended; /* timestamp extension */
    uint24_be   stream_id; /* reserved, must be "\0\0\0" */
    /* body comes next */
} flv_tag;


typedef enum FLV_DMX_STATES_
{
	FLV_DMX_STATE_INIT = 0,
	FLV_DMX_STATE_FLV_HDR = 1,   //expecting/acquiring header
	FLV_DMX_STATE_TAG_A = 2,     //flv audio tag
	FLV_DMX_STATE_TAG_V = 3,     //flv video tag
	FLV_DMX_STATE_TAG_D = 4,     //flv data tag
	FLV_DMX_STATE_TAG_RSRVD = 5, //flv reserved type tag
	FLV_DMX_STATE_V_DATA = 6, //Video data
	FLV_DMX_STATE_A_DATA = 7, //Audio data
	FLV_DMX_STATE_FLV_TAG_END = 8,//expecting/acquiring header
	FLV_DMX_STATE_STOPPED = 9, //stopped
	FLV_DMX_STATE_FLV_TAG_META_DATA = 10, ///metadata parser
	FLV_DMX_STATE_PAUSED = 11,
	FLV_DMX_STATE_NONE = 12,      //Terminated
}FLV_DMX_STATE,*PFLV_DMX_STATE;

typedef struct state_to_string_t
{
	int cstate;
	char state_string[128];
}state_to_string;

state_to_string state2str[] = {
	{FLV_DMX_STATE_INIT                ,"FLV_DMX_STATE_INIT"},
	{FLV_DMX_STATE_FLV_HDR             ,"FLV_DMX_STATE_FLV_HDR"},
	{FLV_DMX_STATE_TAG_A               ,"FLV_DMX_STATE_TAG_A"},
	{FLV_DMX_STATE_TAG_V               ,"FLV_DMX_STATE_TAG_V"},
	{FLV_DMX_STATE_TAG_D               ,"FLV_DMX_STATE_TAG_D"},
	{FLV_DMX_STATE_TAG_RSRVD           ,"FLV_DMX_STATE_TAG_RSRVD"},
	{FLV_DMX_STATE_V_DATA              ,"FLV_DMX_STATE_V_DATA"},
	{FLV_DMX_STATE_A_DATA              ,"FLV_DMX_STATE_A_DATA"},
	{FLV_DMX_STATE_FLV_TAG_END         ,"FLV_DMX_STATE_FLV_TAG_END"},
	{FLV_DMX_STATE_STOPPED             ,"FLV_DMX_STATE_STOPPED"},
	{FLV_DMX_STATE_FLV_TAG_META_DATA   ,"FLV_DMX_STATE_FLV_TAG_META_DATA"},
	{FLV_DMX_STATE_PAUSED              ,"FLV_DMX_STATE_PAUSED"},
	{FLV_DMX_STATE_NONE                ,"FLV_DMX_STATE_NONE"},
};

typedef enum FLV_DMX_AVC_STATES_
{
	FLV_DMX_AVC_DECODER_CONFIG_REC =0,
	FLV_DMX_AVC_NALU,
	FLV_DMX_AVC_STATE_NO_PAYLOAD,
	FLV_DMX_AVC_STATE_NONE
}FLV_DMX_AVC_STATE,*PFLV_DMX_AVC_STATE;

typedef enum FLV_DMX_AAC_STATES_
{
	FLV_DMX_AAC_SEQ_HDR =0,
	FLV_DMX_AAC_RAW,
	FLV_DMX_AAC_STATE_NONE,
}FLV_DMX_AAC_STATE,*PFLV_DMX_AAC_STATE;

typedef enum
{
	DMX_ERR_OK = 0,
	DMX_ERR_INVALID_PARAM,
	DMX_ERR_NON_SUPPORTED_FORMAT,
	DMX_ERR_NON_SUPPORTED_ENCODING,
	DMX_ERR_FUNC_FAILED,
	DMX_ERR_SRC_READ_FAILED,
	DMX_ERR_MAX
}Errtype_e;

typedef struct audioDes_
{
	unsigned char soundFmt;
	unsigned char soundRate;
	unsigned char soundSize;
	unsigned char soundType;
}FLV_AUDIO_DES, *P_FLV_AUDIO_DES;

typedef struct videoDes_
{
	unsigned char videoFrameType;
	unsigned char videoCodec;
}FLV_VIDEO_DES, *P_FLV_VIDEO_DES;

typedef struct SeekPoint_t {
	unsigned int decodeTime;
	unsigned int seekPos;
	char    keyFrame;
	char    video;
	char    audio;
	unsigned int dataSize;
	FLV_AUDIO_DES audDes;
	FLV_VIDEO_DES vidDes;
}FLV_SEEK_POINT, *PFLV_SEEK_POINT;
