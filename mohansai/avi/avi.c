#include "stdio.h"
#include "avi.h"
#include "stdlib.h"
FILE *fpH264 = NULL;
FILE *fpAAC = NULL;
FILE *fpDTS = NULL;
  
	//populate_flv_file_header(&header, buff);


static int print_flv_file_header(avi_header *pheader)
{
	printf("---------header information------------\r\n"); 
	
	printf("-->dwMicroSecPerFrame %d\r\n",pheader->dwMicroSecPerFrame);	
	printf("-->dwMaxBytesPerSec %d\r\n",pheader->dwMaxBytesPerSec);	
	printf("-->dwMaxBytesPerSec %d\r\n",pheader->dwPaddingGranularity);	
	//printf("-->dwMicroSecPerFrame %c\r\n",pheader->dwMicroSecPerFrame);	
//	printf("-->dwMaxBytesPerSec %c\r\n",pheader->dwMaxBytesPerSec);	

	return 0;
}

static int populate_avi_file_header(avi_header *pheader,unsigned char *pbuffer)
{

	((unsigned char *)&pheader-> dwMicroSecPerFrame)[0] = pbuffer[0];
	printf("dwMicroSecPerFrame)[0] %x \r\n ", pbuffer[0]);
	((unsigned char *)&pheader-> dwMicroSecPerFrame)[1] = pbuffer[1];
	printf("dwMicroSecPerFrame)[1] %x \r\n ", pbuffer[1]);
	((unsigned char *)&pheader-> dwMicroSecPerFrame)[2] = pbuffer[2]; 
	printf("dwMicroSecPerFrame)[2] %x \r\n ", pbuffer[2]);
	((unsigned char *)&pheader-> dwMicroSecPerFrame)[3] = pbuffer[3]; 
	printf("dwMicroSecPerFrame)[3] %x \r\n ", pbuffer[3]);
    
	((unsigned char *)&pheader->dwMaxBytesPerSec)[0] = pbuffer[4]; 
	printf("dwMaxBytesPerSec[4] %x \r\n ", pbuffer[4]);
	((unsigned char *)&pheader->dwMaxBytesPerSec)[1] = pbuffer[5]; 
	printf("dwMaxBytesPerSec[5] %x \r\n ", pbuffer[5]);
	((unsigned char *)&pheader->dwMaxBytesPerSec)[2] = pbuffer[6]; 
	printf("dwMaxBytesPerSec[6] %x \r\n ", pbuffer[6]);
	((unsigned char *)&pheader->dwMaxBytesPerSec)[3] = pbuffer[7]; 
	printf("dwMaxBytesPerSec[7] %x \r\n ", pbuffer[7]);
	
 
	((unsigned char *)&pheader-> dwPaddingGranularity)[0] = pbuffer[8]; 
	printf(" dwPaddingGranularity[8] %x \r\n ", pbuffer[8]);
	
	((unsigned char *)&pheader-> dwPaddingGranularity)[1] = pbuffer[9]; 
	printf(" dwPaddingGranularity[9] %x \r\n ", pbuffer[9]);
	
	((unsigned char *)&pheader-> dwPaddingGranularity)[2] = pbuffer[10]; 
	printf(" dwPaddingGranularity[10] %x \r\n ", pbuffer[10]);
	
	((unsigned char *)&pheader-> dwPaddingGranularity)[3] = pbuffer[11]; 
	printf(" dwPaddingGranularity[11] %x \r\n ", pbuffer[11]);
	
  
  
  DWORD dwPaddingGranularity; // pad to multiples of this
/*                                                // size;
    DWORD dwFlags; // the ever-present flags
    DWORD dwTotalFrames; // # frames in file
    DWORD dwInitialFrames;
    DWORD dwStreams;
    DWORD dwSuggestedBufferSize;
    DWORD dwWidth;
    DWORD dwHeight;
    DWORD dwReserved[4];

*/
return 0;
}

read_avi_header(FILE *fp)
{
	unsigned char buff[64];
	int readBytes=0;
	avi_header header;
	
	if (readBytes = fread(buff, sizeof(unsigned char), 56, fp) < 0)
	{
		perror("Read failed");
		exit(1);
	}
	populate_avi_file_header(&header, buff);
	print_flv_file_header(&header);
}
int main()
{
	FILE *fp = fopen(INPUT_FILE_PATH, "rb");
	fpH264   = fopen(OUTPUT_VIDEO_ES_PATH, "wb");
	fpAAC    = fopen(OUTPUT_AUDIO_ES_PATH , "wb");

	if(( NULL == fp )||( NULL == fpH264)||(NULL == fpAAC))
	{
		printf("Failed to open the filein avi \r\n");
		exit(1);
	}

	read_avi_header(fp);

	fclose(fp);
	fclose(fpH264);
	fclose(fpAAC);

	return 0;
}
