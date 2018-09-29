
#include "stdbool.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

main()
{

	open("sixth.flv", O_RDONLY, 0777);

}
