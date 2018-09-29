#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdbool.h"
#include "stdlib.h"
#include "defs.h"

int dump_audio_tag()
{
	int len = 0, wretval = 0;
	char buffer[1024] = " ";
	extern fd2;

	switch(adata.soundtype)
	{
		case 0 :
			len += sprintf(buffer + len, "<type:\"mono\" ");
			break;

		case 1 :
			len += sprintf(buffer + len, "<type:\"stereo\" ");
			break;
	}

	switch(adata.soundsize)
	{
		case 0 :
			len += sprintf(buffer + len, "size:\"8 bit samples KHz\" ");
			break;

		case 1 :
			len += sprintf(buffer + len, "size:\"16 bit samples KHz\" ");
			break;
	}


	switch(adata.soundrate)
	{
		case 0 :
			len += sprintf(buffer + len, "rate:\"5.5 KHz\" ");
			break;

		case 1 :
			len += sprintf(buffer + len, "rate:\"11 KHz\" ");
			break;

		case 2 :
			len += sprintf(buffer + len, "rate:\"22 KHz\" ");
			break;

		case 3 :
			len += sprintf(buffer + len, "rate:\"44 KHz\" ");
			break;
	}

	switch(adata.soundformat)
	{
		case 0 :
			len += sprintf(buffer + len, "format:\"linear PCM, platform	Endian\">\n");
			break;

		case 1:
			len += sprintf(buffer + len, "format:\"ADPCM\">\n");
			break;

		case 2:
			len += sprintf(buffer + len, "format:\"MP3\">\n");
			break;
		
		case 3:
			len += sprintf(buffer + len, "format:\"linear PCM, little Endian\">\n");
			break;
		
		case 4:
			len += sprintf(buffer + len, "format:\"Nellymoser 16KHz mono\">\n");
			break;
		
		case 5:
			len += sprintf(buffer + len, "format:\"Nellymoser 8 KFz mono\">\n");
			break;
		
		case 6:
			len += sprintf(buffer + len, "format:\"Nellymoser\">\n");
			break;
		
		case 7:
			len += sprintf(buffer + len, "format:\"G.711 A-law Algorithmic PCM\">\n");
			break;
		
		case 8:
			len += sprintf(buffer + len, "format:\"G.711 mu-law Algorithmic	PCM\">\n");
			break;
		
		case 9:
			len += sprintf(buffer + len, "format:\"reserved\">\n");
			break;
		
		case 10:
			len += sprintf(buffer + len, "format:\"AAC\">\n");
			break;
		
		case 11:
			len += sprintf(buffer + len, "format:\"Speex\"> ");
			break;
		
		case 14:
			len += sprintf(buffer + len, "format:\"MP3 KHz\">\n");
			break;
		
		case 15:
			len += sprintf(buffer + len, "format:\"Device specific sound\">\n");
			break;
	}

	if(adata.aacpackettype == 0);
	//len += sprintf(buffer + len, "format:\"AAC sequence header\"> ");
	else if(adata.aacpackettype == 1);	
	//len += sprintf(buffer + len, "format:\"AAC raw\"> ");

	wretval = write(fd2, buffer, len);

	printf("%s\n", buffer);

	return 0;
}
