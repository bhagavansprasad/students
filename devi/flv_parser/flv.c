#include "flv.h"


int main()
{
	struct flv_file_header fhead;
	struct flv_tag thead;
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

	for(i=0;i<=9;i++)
	{
		r = read_flv_header(rfd,buff, 16);
		parse_flv_tag(buff , 16, &thead);
		dump_flv_tag(&thead);
		lseek(rfd,(thead.data_size)-1,1);
	}

}
