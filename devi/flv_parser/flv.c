#include "flv.h"


int main()
{
	struct flv_file_header fhead;
	struct flv_tag_header thead;
	int rfd = 0, len = 9, r, i;
	char buff[100];
	rfd = open("sixth.flv",O_RDONLY,0777);

	if(rfd <0)
	{
		perror("file cant be open bcoz");
		exit(0);
	}

	r = read_flv_header(rfd, buff, len);
	parse_flv_header(buff, len, &fhead);
	dump_flv_header(&fhead);
	

	/*tag header*/
	r = read_flv_parser(rfd, buff, 12);
	parse_flv_tag_header(buff, 12, &thead);
	dump_flv_tag_header(&thead);
}
