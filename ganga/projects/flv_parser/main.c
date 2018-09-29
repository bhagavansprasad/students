#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"
#include "defs.h"

#define SCRIPT_DATA   18
#define VIDEO_TAG_DATA 9
#define AUDIO_TAG_DATA 8

int offset;
int main()
{
	int fd = 0;

	fd = open("sixth.flv", O_RDONLY, 0744);
	printf("fd value is :%d\n", fd);

	read_flv_header(fd);
	dump_flv_header();
	read_flv_body(fd);

	return 0;
}

int read_flv_body(int fd)
{
	int len = 0, i = 0, n = 0, taglen = 0;
	char buffer[1024] = " ";

	while(1)
	{
		int rd = 0;
		n = read_flv_tags(fd);

		switch (n)
		{
			case SCRIPT_DATA:
				dump_flv_tag();
				//read_script_data_tag();
				//dump_script_data_tag();
				break;

			case VIDEO_TAG_DATA:
				dump_flv_tag();
				rd = read_video_tag(fd);
				dump_video_tag();
				break;

			case AUDIO_TAG_DATA:
				dump_flv_tag();
				rd = read_audio_tag(fd);
				dump_audio_tag();
				break;
		}

		i++;
		if(n == 1)
			exit(0);

		taglen = (tdata.data_size - rd);

		offset = lseek(fd, taglen, SEEK_CUR);
	}
	return 0;
}
