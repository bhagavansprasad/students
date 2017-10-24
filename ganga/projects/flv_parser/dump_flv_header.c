#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdbool.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "defs.h"

int fd1, fd2, fd3;
int dump_flv_header()
{
	int wretval = 0, len = 0;
	extern offset;
	offset = hdata.data_offset;
	char buffer[1024] = " ";

	fd1 = open("t.txt", O_CREAT | O_APPEND | O_RDWR, 0644);
	fd2 = open("a.txt", O_CREAT | O_APPEND | O_RDWR, 0744);
	fd3 = open("v.txt", O_CREAT | O_APPEND | O_RDWR, 0644);

	len += sprintf(buffer, "<type:\"%s\" ", hdata.sign);

	len +=  sprintf(buffer + len, "hasVedio:\"%s\" ", (hdata.vedio_bit ? "true" : "false"));

	len += sprintf(buffer + len, "hasAudio:\"%s\" ", (hdata.audio_bit ? "true" : "false"));

	len += sprintf(buffer + len, "version:\"%d\">\n", hdata.version);


	printf("buffer is :%s\n", buffer);

	wretval = write(fd1, buffer, len);

	return 0;
}

int dump_flv_tag()
{
	extern fd2, fd3;
	int wretval = 0, tslen = 0 , len = 0;
	static a = 1;
	extern fd1, offset; 
	char buffer[1024] = " ";
	char tempbuff[1024] = " ";

	len += sprintf(buffer+len , "<tag%d>\n", a);

	switch(tdata.tag_type)
	{
		case 18 :
			len += sprintf(buffer + len, "<tagtype:\"scriptdata\" ");
			break;

		case 9 :
			len += sprintf(buffer + len, "<tagtype:\"video\" ");
			break;

		case 8 :
			len += sprintf(buffer + len, "<tagtype:\"audio\" ");
			break;
	}

	len += sprintf(buffer + len, "timestamp:\"%d\" ", tdata.timestamp);
	len += sprintf(buffer + len, "datasize:\"%d\" ", tdata.data_size);
	len += sprintf(buffer + len, "offset:\"%d\">", (offset+4));

	if(tdata.tag_type == 8)
		wretval = write(fd2, buffer, len);

	else if(tdata.tag_type == 9)
	{
		wretval = write(fd3, buffer, len);
	}

	else
		wretval = write(fd1, buffer, len);

	printf("%s\n", buffer);

	fflush(stdout);
	a++;

	return 0;
}
