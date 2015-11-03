#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "unistd.h"
#include "fcntl.h"
#include "math.h"
#include "ctype.h"
#define LEN 9

struct header
{
	char signature;
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
};
