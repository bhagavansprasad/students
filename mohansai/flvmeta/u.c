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

	int nob = 0,count=0,temp=0;
	unsigned char buff[1000]; 
	unsigned char audio_buff[1000];
	unsigned char video_buff[1000];
	unsigned int prev_tagsize;
	unsigned int bodylength;
	unsigned int timestamp;

	while(1)
	{
		nob = fread(buff, sizeof(unsigned char), 25, fp);
		
		if(nob < 25)
		{
			printf("\t\t\t------------file ended----------\r\n");
			break;
		}
	
//		printf("prevtag: %x %x %x %x\r\n", buff[0], buff[1], buff[2], buff[3]);
//		printf("blength: %x %x %x \r\n", buff[6], buff[7], buff[8]);
		
		printf("buff and nob: %d--%x\r\n\n",nob, buff[4]);	
		
		if(buff[4] == 8 )
		{
			if(count==0)
				count++;
			else 		
			{
			/*	buff[0]=0;
				buff[1]=audio_buff[6];
				buff[2]=audio_buff[7];
				buff[3]=audio_buff[8];
		*/

				buff[0]=0;
				buff[1]=audio_buff[5];
				buff[2]=audio_buff[6];
				buff[3]=audio_buff[7];
				//		printf("video-->%x %x %x\r\n", audio_buff[6],audio_buff[7],audio_buff[8]);
		//		printf("video-->%x %x %x %x\r\n", buff[0], buff[1], buff[2], buff[3]);
			}
			((unsigned char *)&prev_tagsize)[0] = buff[3];
			((unsigned char *)&prev_tagsize)[1] = buff[2];
			((unsigned char *)&prev_tagsize)[2] = buff[1];
			((unsigned char *)&prev_tagsize)[3] = buff[0];
		
			
	
			((unsigned char *)&bodylength)[0] = buff[7];
			((unsigned char *)&bodylength)[1] = buff[6];
			((unsigned char *)&bodylength)[2] = buff[5];
			((unsigned char *)&bodylength)[3] = 0;

			((unsigned char *)&timestamp)[0] = buff[10];
			((unsigned char *)&timestamp)[1] = buff[9];
			((unsigned char *)&timestamp)[2] = buff[8];
			((unsigned char *)&timestamp)[3] = 0;
			
			printf("  prev_tagsize \"%d\"type=\"audio\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",
				prev_tagsize,timestamp, bodylength, (ftell(fp)-11) );


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
				buff[0]=0;
				buff[1]=video_buff[5];
				buff[2]=video_buff[6];
				buff[3]=video_buff[7];
				
		//		printf("audio-->%x %x %x\r\n", video_buff[6],video_buff[7],video_buff[8]);
		//		printf("audio-->%x %x %x %x\r\n", buff[0], buff[1], buff[2], buff[3]);
			}
		
			((unsigned char *)&prev_tagsize)[0] = buff[3];
			((unsigned char *)&prev_tagsize)[1] = buff[2];
			((unsigned char *)&prev_tagsize)[2] = buff[1];
			((unsigned char *)&prev_tagsize)[3] = buff[0];

			((unsigned char *)&bodylength)[0] = buff[7];
			((unsigned char *)&bodylength)[1] = buff[6];
			((unsigned char *)&bodylength)[2] = buff[5];
			((unsigned char *)&bodylength)[3] = 0;

			((unsigned char *)&timestamp)[0] = buff[10];
			((unsigned char *)&timestamp)[1] = buff[9];
			((unsigned char *)&timestamp)[2] = buff[8];
			((unsigned char *)&timestamp)[3] = 0;

			printf("  prev_tagsize \"%d\"type=\"video\" timestamp=\"%d\" dataSize=\"%d\" offset=\"%ld\">\r\n",
				prev_tagsize,timestamp, bodylength, (ftell(fp)-11) );
			fwrite(buff,sizeof(unsigned char),25,fv);
			memcpy(video_buff, buff, 25);
		}
	}
	return 0;
}


