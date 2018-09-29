#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


static int read_audio_video(FILE *fp,FILE *fa,FILE *fv,FILE *fd);
main()
{
	FILE *fp;
	FILE *fv;
	FILE *fa;
	FILE *fd;
	fp = fopen("4tags.flv","rb");
	fv = fopen("video.flv","wb");
	fa = fopen("audio.flv","wb");
	if(fp==NULL)
	{
		perror("error in open a file");
		exit(1);
	}
	read_audio_video(fp,fa,fv,fd);
}

static int read_audio_video(FILE *fp,FILE *fa,FILE *fv,FILE *fd)
{

	int nob = 0,type=0,count=0,temp=0;
	unsigned char buff[1000]; 
	unsigned char audio_buff[1000];
	unsigned char video_buff[1000];
	
	while(1)
	{
		nob = fread(buff, sizeof(unsigned char), 25, fp);
		
		if(nob < 25)
		{
			printf("\t\t\t------------file ended----------\r\n");
			break;
		}
	
		printf("prevtag: %x %x %x %x\r\n", buff[0], buff[1], buff[2], buff[3]);
		printf("blength: %x %x %x \r\n", buff[6], buff[7], buff[8]);
		
		printf("buff and nob: %d--%x\r\n\n",nob, buff[4]);	
		
		if(buff[4] == 8 )
		{
			if(count==0)
				count++;
			else 		
			{
				buff[0]=audio_buff[5];
				buff[1]=audio_buff[6];
				buff[2]=audio_buff[7];
				buff[3]=0;

				printf("audiobuff-->%x %x %x\r\n", audio_buff[6],audio_buff[7],audio_buff[8]);
				printf("buff-->%x %x %x %x\r\n", buff[0], buff[1], buff[2], buff[3]);
			}

			fwrite(buff, sizeof(unsigned char), 25, fa);
			memcpy(audio_buff, buff, 25);
		}
		else if(buff[4] == 9)
		{
			if(temp==0)
			{
				temp++;
			}
			else
			{
				buff[0]=video_buff[5];
				buff[1]=video_buff[6];
				buff[2]=video_buff[7];
				buff[3]=0;
				
				printf("videobuff-->%x %x %x\r\n", video_buff[6],video_buff[7],video_buff[8]);
				printf("buff-->%x %x %x %x\r\n", buff[0], buff[1], buff[2], buff[3]);
			}

			fwrite(buff,sizeof(unsigned char),25,fv);
			memcpy(video_buff, buff, 25);
		}
	}
	return 0;
}

/*
   static int read_audio_video_tag(FILE *fp,FILE *fa,FILE *fv)
   {
   while(1)
   {
   read_bytes_from_file(25, to_buffer);

   copy_buffer_to(tempbuff)
   check_type if it is 8 i.e. Audio
   if so 
   {
   if (the packet is is second)
   {
   copy body_length of first tag to previous_tag_size of second tag
   b[0] = pvebuff[6]
   b[1] = pvebuff[7]
   b[2] = pvebuff[8]
   b[4] =  0
   }
   write_buffer_to(new_audio_file, to_buffer)
   }
   else if not
   {
   if (the packet is is second)
   {
//copy body_length of first tag to previous_tag_size of second tag
printf("%x", b[0]);
printf("%x", b[1]);
printf("%x", b[2]);
printf("%x", b[4]);
printf("%x", tb[0]);
printf("%x", tb[1]);
printf("%x", tb[2]);
printf("%x", tb[4]);

b[0] = pvebuff[6]
b[1] = pvebuff[7]
b[2] = pvebuff[8]
b[4] =  0
}
write_buffer_to(new_audio_file, to_buffer)
}
}
}
 */


