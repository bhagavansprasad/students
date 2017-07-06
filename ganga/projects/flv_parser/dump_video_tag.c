#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdbool.h"
#include "stdlib.h"
#include "defs.h"

int dump_video_tag()
{
	int len = 0, wretval = 0;
	char buffer[1024] = " ";
	extern timestamp, fd3;

	switch(vdata.codecID)
	{
		case 2 :
			len += sprintf(buffer + len, "<codecID:\"sorenson H.263\" ");
			break;

		case 3 :
			len += sprintf(buffer + len, "<codecID:\"Screen video\" ");
			break;

		case 4 :
			len += sprintf(buffer + len, "<codecID:\"On2 VP6\" ");
			break;

		case 5 :
			len += sprintf(buffer + len, "<codecID:\"On2 VP6 with alpha channel\" ");
			break;

		case 6 :
			len += sprintf(buffer + len, "<codecID:\"Screen video version2\" ");
			break;

		case 7 :
			len += sprintf(buffer + len, "<codecID:\"AVC\" ");
			break;
	}

	switch(vdata.frame_type)
	{
		case 1 :
			len += sprintf(buffer + len, "FrameType:\"keyframe\">\n");
			break;

		case 2 :
			len += sprintf(buffer + len, "FrameType:\"inter frame\">\n");
			break;

		case 3 :
			len += sprintf(buffer + len, "FrameType:\"disposal inter frame\">\n");
			break;

		case 4 :
			len += sprintf(buffer + len, "FrameType:\"generated keyframe\">\n");
			break;

		case 5 :
			len += sprintf(buffer + len, "FrameType:\"video info/command frame\">\n ");
			break;
	}

	wretval = write(fd3, buffer, len);

	printf("%s\n", buffer);

	return 0;
}
