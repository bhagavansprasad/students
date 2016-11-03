#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define len_head 9
#define len_tag 15
#define audio_header 2
#define video_header 6
#define script_header 13
#define SIGNATURE_LEN 3

struct flv_file_header
{
	unsigned char signature[3];
	unsigned int version;
	bool is_video;
	bool is_audio;
	unsigned int offset;
};

struct audio_data
{
	/*enum frame{keyframe=1,interframe,dis_interframe,gen_keyframe,video_infoframe}frame_type;
	enum id{sorenson=2,screenvideo,on_vp,on_vp_alpha,screenvideo_version,AVC}codec_id;
	enum avc{AVC_seq_header,AVC_NALU,AVC_end}AVC_packet_type;*/
	unsigned int soundformat;
	unsigned int soundrate;
	unsigned int soundsize;
	unsigned int soundtype;
	unsigned int AACpackettype;

};

struct video_data
{
	unsigned int frame_type;
	unsigned int codec_id;
	unsigned int AVC_type;
	unsigned int com_time;
	unsigned int video_body;
};

struct script_data
{
	unsigned char object_name;
	unsigned char string_len;
	unsigned char string_data[20];

};

union tags_data
{
	struct audio_data audio;
	struct video_data video;
	struct script_data script;
};

struct flv_tag_header
{
	unsigned int pr_tag;
	enum tag{audio = 8,video = 9,script = 18}tag_type;
	unsigned int data_size;
	unsigned int time;
	unsigned int time_ex;
	unsigned int stream_id;
	union tags_data tdata;
};
