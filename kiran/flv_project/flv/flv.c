#include "flv.h"
#include "fn_declaration.h"

extern int a,v,s;

int t = 0;
int main()
{
	struct flv_file_header fhead;
	struct flv_tag_header thead;
	unsigned int rfd = 0,afd = 0, vfd = 0, r, i, offset = 0, tags = 0;
	unsigned char buff[100];
	rfd = open("sixth.flv",O_RDONLY,0777);
	afd = open("audio.flv",O_CREAT|O_RDWR,0777);
	vfd = open("video.flv",O_CREAT|O_RDWR,0777);

	r = read_flv_header(rfd, buff, len_head);
	parse_flv_header(buff, len_head, &fhead);
	dump_flv_header(&fhead);

	offset = fhead.offset;

	printf("\nFLV_TAGS_INFORMATION :::>\n\n");

	while(1)
	{
		t += offset;
		lseek(rfd, t,SEEK_SET);
		r = read_flv_header(rfd, buff, len_tag);
		parse_flv_tag(buff, len_tag, &thead);
		if(thead.tag_type != 8 && thead.tag_type != 9 && thead.tag_type != 18)
			break;
		tags++;
		dump_flv_tag(&thead);
		offset = thead.data_size + len_tag;

		if(thead.tag_type == audio)
		{
			lseek(rfd, 0, SEEK_CUR);
			r = read_flv_header(rfd, buff, audio_header);
			parse_flv_audio_header(buff, audio_header,&fhead);
			write(afd,&thead,sizeof(thead));
			//dump_flv_audio_header(&fhead);
		}
		if(thead.tag_type == video)
		{
			lseek(rfd, 0, SEEK_CUR);
			r = read_flv_header(rfd, buff, video_header);
			parse_flv_video_header(buff, video_header, &fhead);
			write(vfd,&thead,sizeof(thead));
			//dump_flv_video_header(&fhead);
		}
		else if(thead.tag_type == script)
		{
			lseek(rfd, 0, SEEK_CUR);
			r = read_flv_header(rfd, buff, script_header);
			parse_flv_script_header(buff, script_header, &fhead);
			dump_flv_script_header(&fhead);
		}
	}
	printf("total no of tags ----> %d (audio = %d), (video = %d), (script = %d)\n",tags,a,v,s);
	return 0;
}
