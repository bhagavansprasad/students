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
<<<<<<< HEAD
=======

>>>>>>> 3290c4c42e7183eecd754ca86f033ddcf8543899
