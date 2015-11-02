#include "flv.h"


int main()
{
	struct flv_file_header fhead;
	struct flv_tag thead;
	int rfd = 0, len = 9, r, i;
	char buff[100],ruff[100];
	rfd = open("sixth.flv",O_RDONLY,0777);

	if(rfd <0)
	{
		perror("file cant be open bcoz");
		exit(0);
	}

	r = read_flv_header(rfd, buff, len);
	parse_flv_header(buff, len, &fhead);
	dump_flv_header(&fhead);
	//lseek(rfd,9,1);
	r = read_flv_header(rfd,buff, 12);
	parse_flv_tag(buff , 12, &thead);
	dump_flv_tag(&thead);
}
