#include "stdio.h"
#include "stdlib.h"
#define INPUT_FILE_PATH    "t.flv"
#define MAX_STACK_BUFF 30*1024
static int read_audio_tag(FILE *fa);
main()
{
	FILE *fa;
	fa = fopen("t.flv","rb");
	if(fa==NULL)
	{
		perror("error in open a file");
		exit(1);
	}
	read_audio_tag(fa);
}

static int read_audio_tag(FILE *fa)
{
	unsigned char buff[MAX_STACK_BUFF] = "\0";
	unsigned int prev_tagsize;
	unsigned char type;
	unsigned int bodylength;
	unsigned int timestamp;
	int count=0;
		
	while(1)
	{
		count=fread(buff, sizeof(unsigned char),25, fa);
		if( count < 25 )
		{
		//	perror("there is a problem in file ");
			break;
		}


		((unsigned char *)&prev_tagsize)[0] = buff[3];
		((unsigned char *)&prev_tagsize)[1] = buff[2];
		((unsigned char *)&prev_tagsize)[2] = buff[1];
		((unsigned char *)&prev_tagsize)[3] = buff[0];
		//printf("previous_tag %d\n\r",prev_tagsize );
		
		type = buff[4];
		//printf("type %d\r\n",type);
		
		((unsigned char *)&bodylength)[0] = buff[7];
		((unsigned char *)&bodylength)[1] = buff[6];
		((unsigned char *)&bodylength)[2] = buff[5];
		((unsigned char *)&bodylength)[3] = 0;
		//printf("bodylength %d\r\n ", bodylength);
		
		((unsigned char *)&timestamp)[0] = buff[10];
		((unsigned char *)&timestamp)[1] = buff[9];
		((unsigned char *)&timestamp)[2] = buff[8];
		((unsigned char *)&timestamp)[3] = 0;
	
			printf("prevtagsix = %d type = %d bodylength = %d timestam = %d	offset = %ld\r\n ",
			prev_tagsize,type,bodylength,timestamp,ftell(fa));

	}	
	return 0;
}


