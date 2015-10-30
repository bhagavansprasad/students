#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIGNATURE_LEN 3

#pragma pack(1)
struct flv_file_header
{
	char signature[10];
	unsigned char version;
	bool is_video;
	bool is_audio;
	unsigned int offset;
};
enum tagtype
	{
	audio=8,
	video=9,
	script=19
	};

struct flv_tag
{
	unsigned int prev_tag_size:32;
	enum tagtype t;
	unsigned int data_size:24;
	unsigned int time_stamp:24;
	unsigned int time_stamp_extended:8;
};


int read_flv_header(int, char *, int);
void parse_flv_header(char *, int, struct flv_file_header *);
void dump_flv_header(struct flv_file_header *);
void parse_flv_tag(char *, int, struct flv_tag *);
void dump_flv_tag(struct flv_tag *);
