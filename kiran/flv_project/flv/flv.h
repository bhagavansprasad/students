#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define SIGNATURE_LEN 3
struct flv_file_header
{
	char signature[10];
	unsigned int version;
	bool is_video;
	bool is_audio;
	unsigned int offset;
};
