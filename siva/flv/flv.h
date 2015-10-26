#pragma packoff(1)

/* HEADER STRUCTURE */

typedef struct header 
{
	unsigned char signature[4];
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
	unsigned char stream_id[4];
	}flv_tag;

/*SCRIPT DATA*/
typedef struct metadata
{
unsigned char script_type;
}flv_meta_data;





/* VIDEO STRUCTURE */
typedef struct video
{
unsigned char frame_codec;
unsigned char avc_packet_type;
signed char composition_time[4];
}flv_video;

/* VIDEO_BODY */
typedef struct v_body
{
unsigned char video_tag_body;
}video_body;

/*AUDIO STRUCTURE*/
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

/* check tha audio tag R video Tag in FLV_file_body*/


#define TAG_META_DATA 18
#define TAG_AUDIO_DATA 8
#define TAG_VIDEO_DATA 9
#define KEY_FRAME 1
#define INTER_FRAME 2
#define DISPOSABLE_INTER_FRAME 3
#define GENERATED_KEY_FRAME 4
#define VIDEO_INFO_R_COMMAND_FRAME 5
#define SORENSON_H_263 2
#define SCREEN_VIDEO 3
#define ON2_VP6 4
#define ON2_VP6_ALPHA_CHANNEL 5
#define SCREEN_VIDEO_VERSION2 6
#define AVC 7
#define AVC_SEQUENCE_HEADER 0
#define AVC_NALU 1
#define AVC_END_SEQUENCE 2
#define LINEAR_PCM_PLATFORM_ENDIAN 0
#define ADPCM 1
#define MP3 2
#define LINEAR_PCM_LITTLE_ENDIAN 3
#define NELLYMOSER_16_KHZ_MONO 4
#define NELLYMOSER_8_KHZ_MONO 5
#define NELLYMOSER 6
#define G_711_A_LAW_LOGARITHMIC_PCM 7
#define G_711_MU_LAW_LOGARITHMIC_PCM 8
#define RESERVED 9
#define AAC 10
#define SPEEX 11
#define MP3_8_KHZ 14
#define DEVICE_SPECIFIC_SOUND 15
#define SAMPLING_RATE_5_5_KHZ 0
#define SAMPLING_RATE_11_KHZ 1
#define SAMPLING_RATE_22_KHZ 2
#define SAMPLING_RATE_44_KHZ 3
#define MONO 0 
#define STEREO 1
#define BIT_8_SAMPLES 0
#define BIT_16_SAMPLES 1
#define NO_PRE_PROCESSING 0
#define PRE_PROCESSING 1
#define NUMBER 0
#define BOOLEAN 1
#define STRING 2
#define OBJECT 3
#define MOVE_CLIP 4
#define Null 5
#define UNDEFINED 6
#define REFERENCE 7
#define ECMA_ARRAY 8
#define OBJECT_END_MARKER 9
#define STRICT ARRAY 10
#define DATE 11
#define LONG_STRING 12



/* prototypes of functions*/
int open_file(char *filename);
void read_header(int fd,flv_header *header);


int read_tag(int fd,flv_tag *tag);
void check_tag_type(int fd,unsigned char *tagg,int *size,unsigned char, unsigned int,unsigned int *);

void check_position(int n,int pos1,int pos3);
void read_video_data(int fd,flv_video *video,unsigned char filter);
//void check_time(unsigned char *,unsigned char *,unsigned char *);
int check_avc_packet_type(unsigned char *packet,unsigned char *codec_id);
int check_frame_type(unsigned char *cf);
void dump_flv_body(flv_tag  *bh,int size,unsigned int,unsigned int );
int check_sound_format(unsigned char *audio);
void check_sound_rate(unsigned char *sound);
void check_sound_size(unsigned char *sound);
void check_sound_type(unsigned char *s); 
int check_aac_packet_type(unsigned char *sound_format,unsigned char *aac);
void check_sound_data(unsigned char *sound_format,unsigned char aac_packet_type);
void check_aac_audio_packet(unsigned char aac_packet_type);
void read_audio_data(int fd,flv_audio *audio,unsigned char filter);
void check_avc_video_packet(unsigned char *avc_packet_type);
void check_video_body(unsigned char *frame_id,unsigned char *codec_id);
void check_video_encrypted(unsigned char filter);
void check_audio_encrypted(unsigned char filter);
int check_filter_type(int fd, unsigned char *type, int *size);






