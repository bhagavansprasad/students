#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include "flv.h"

int read_flv_header(int, char *,int);
void parse_flv_header(char *, int, struct header *);
void dump_flv_header(struct header *);

int read_flv_tag(int,char *, int);
void parse_flv_tag(char *, int ,struct flv_tag *);
void dump_flv_tag(struct flv_tag *);

main()
{
	struct header fhead;
	struct flv_tag ftag;

	int fd = 0, r = 0, r1 = 0;
	char buff[128];

	fd = open("sixth.flv", O_RDONLY, 0777);

	r = read_flv_header(fd, buff, 9);
	parse_flv_header(buff, 9, &fhead);
	dump_flv_header(&fhead);

	lseek(fd, 0, SEEK_CUR);
	r1 = read_flv_tag(fd, buff,15);
	parse_flv_tag(buff, 15, &ftag);
	dump_flv_tag(&ftag);
	
	/*int size = 9, i = 0, j = 0;
	for(i = 0; i <10; i++)
	{
		size+= 15+ftag.datasize;
		lseek(fd, size, SEEK_SET);
		r1 = read_flv_tag(fd, buff,15);
		parse_flv_tag(buff, 15, &ftag);
		dump_flv_tag(&ftag);
	}*/

}
