#include<stdio.h>
#include"flv.h"


void pass_info(int k,int p, int set)
{

	short int c = 34;

	printf("timestamp=%c%d%c ",c,p,c);
	printf("dataSize= %c%d%c ",c,k,c);
	printf("offset=%c%d%c>\n",c,set,c);

}
int audio_tag(char x)
{
	if(x==0)
	{
		printf("no audio tag are present%d\n",x);
	}
	if(x==1)
	{
		printf("audio tag are prasent%d\n",x);
	}
	else
	{
		return 1;
	}
}
int video_tag(char y)
{
	if(y==0)
	{
		printf("no video tag are present%d\n",y);
	}
	if(y==1)
	{
		printf("video tag are present%d\n",y);
	}
	else
	{
		return 1;
	}
}



/*  videotag  */
void get_frametype(char x)
{
	int a;
	a = x>>4;
	short int c = 34 ;
	switch(a)
	{
		case 1:printf("frameType=%ckeyframe%c/>\n</tag>\n",c,c);
			   break;
		case 2:printf("frameType=%cinter frame%c>\n</tag>\n",c,c);
			   break;
		case 3:printf("disposable_in_frame\n</tag>\n");
			   break;
		case 4:printf("genarated_k_frame\n</tag>\n");
			   break;
		case 5:printf("video_info  \n</tag>\n");
			   break;
		default:printf("frameType=%cinter frame%c/>\n",c,c);
	}
}

void get_codecID(char x)
{
	int i,k;
	short int c=34;
	i=x<<4;
	k=i>>4;

	switch(k)
	{
		case 2:printf("<videoData codecID=%csorenson h.263%c ",c,c);
			   break;
		case 3:printf("<screen video ");
			   break;
		case 4:printf("videoData codecID=%con2 VP6%c ",c,c);
			   break;
		case 5:printf("videoData codecID=%con2 VP6 with alpha channel%c ",c,c);
			   break;
		case 6:printf("videoData codecID=%cscreen video vrsion 2%c ",c,c);
			   break;
		case 7:printf("<AVC ");
			   break;
		default:printf("videoData codecID=%cAAC%c ",c,c);
	}
}

/*void get_compositiontime (unsigned char n)
  {
  int a;
  char *p=&a;

 *(p+3)=0;
 *(p+2)=n[0];
 *(p+1)=n[1];
 *(p+0)=n[2];

 printf(" compositiontime= %d", a);

 }*/

/*  audio tag  */
void get_soundtypes( unsigned char x)
{
	int h,k,t,r;
	h=x>>4;
	k=(x>>2)&3;
	t=(x>>1)&1;
	r=x&1;
	short int c = 34;

	switch(r)
	{
		case 0:printf("<audioData type=stereo");
			   break;
		case 1:printf("<audioData type=%cstereo%c",c,c);
			   break;
	}

	switch(t)
	{
		case 0:printf("8-bit sample");
			   break;
		case 1:printf(" size=%c16%c",c,c );
			   break;
		default:printf("no size of sample");
	}
	switch(k)
	{
		case 0:printf("rate:5.5 ");
			   break;
		case 1:printf("rate:11 ");
			   break;
		case 2:printf("rate:22 ");
			   break;
		case 3:printf(" rate=%c44%c",c,c );
			   break;
		default:printf("no sound rate");
	}

	if(h==0)
	{
		printf("linear pcm=%d",h);
	}
	if(h==1)
	{
		printf("adpcm     =%d",h);
	}
	if(h==2)
	{
		printf("mp3       =%d",h);
	}
	if(h==3)
	{
		printf("linear pcm =%d",h);
	}
	if(h==4)
	{
		printf("nelly_16khz=%d",h);
	}

	if(h==5)
	{
		printf("nelly_8khz=%d",h);
	}
	if(h==6)
	{
		printf("nellymoser=%d",h);
	}
	if(h==7)
	{
		printf("g.711 A-law=%d",h);
	}
	if(h==8)
	{
		printf("g.711 mu-law=%d",h);
	}
	if(h==9)
	{
		printf("reserved    =%d",h);
	}
	if(h==10)
	{
		printf("format=%cAAC%c/>\n",c,c,h);
	}
	if(h==11)
	{
		printf("speex       =%d",h);
	}
	if(h==14)
	{
		printf("mp3 8khz    =%d",h);
	}
	if(h==15)
	{
		printf("device-sound =%d",h);
	}
	else
	{
		printf("</tag>\n");
	}

}

/*void get_aacpackettype(x)
  {
  if(x==0)
  {
  printf("AACsequence header%d",x);
  }
  if(x==1)
  {
  printf("AAC raw%d",x);
  }
  else
  {
  printf("not valid sound size\n");
  }
  }*/


