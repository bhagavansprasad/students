#define LEN 9
#include "stdbool.h"

struct header
{
	char     signature[128];
	unsigned int version;
	bool is_audio;
	bool is_video;
	unsigned int offset;
};
struct flv_tag
{
	unsigned int previous_tags;
	enum tag_type{
	audio = 8,
	video = 9,
	scriptdata = 18
	}Ttype;
	unsigned int datasize;
	unsigned int timestamp;
	unsigned int tsExtended;
	unsigned int streamid;
};
struct audio_tags
{
	enum sound_format{
	uncompressed = 0;
	ADPCM = 1;
	MP3 = 2;
	nellymoser_mono = 5;
	nelllymoser = 6
	}sound_form;
	





	

	<F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11><F11>
}
