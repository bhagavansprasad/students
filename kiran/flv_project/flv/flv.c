#include "flv.h"

int main()
{
	struct flv_file_header fhead;
	int rfd = 0, len = 9, r, i;
	char buff[100];
	rfd = open("sixth.flv",O_RDONLY,0777);

	r = read_flv_header(rfd, buff, len);
	parse_flv_header(buff, len, &fhead);
//	dump_flv_header(&fhead);
}
