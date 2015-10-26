#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include "audio_video.h"


main()
{
	int fd,audio_fd,video_fd,r;
	flv_header hd;
	flv_tag th;
	fd=file_open("sixth.flv");
	audio_fd = create_audio_file("audio.flv");
	video_fd = create_video_file("video.flv");
	write_audio_header(fd,audio_fd);
	write_video_header(fd,video_fd);
<<<<<<< audio_video.c
	

=======
	lseek(fd,9,SEEK_CUR);
	r=read_tag(fd,th,audio_fd,video_fd);
	for(;r>=4;)
	{
	r=read_tag(fd,th,audio_fd,video_fd);
	}
   printf("end\n");
>>>>>>> 1.2
}

