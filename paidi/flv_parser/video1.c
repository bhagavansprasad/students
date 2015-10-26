#include<stdio.h>
#include"flv_v.h"

void get_frametype(char y)
{
	int a,x;
	x=y>>4;
	short int c=34;
	if(x==1)
	{
		printf("frameType=%ckeyframe%c/>\n</tag>\n",c,c);
	}
	if(x==2)
	{
		printf("frameType=%cinter frame%c>\n</tag>\n",c,c);
	}
	if(x==3)
	{
		printf("disposable_in_frame\n</tag>\n");
	}
	if(x==4)
	{
		printf("genarated_k_frame\n</tag>\n");
	}
	if(x==5)
	{
		printf("video_info  \n</tag>\n");
	}
	else
	{
		printf("frameType=%cinter frame%c/>\n",c,c);
	}
}

void get_codecID(char x)
{
	int a,i;
	a=x<<4;
	i=a>>4;
	short int c = 34;
	if(i==2)
	{
		printf("<videoData codecID=%csorenson h.263%c ",c,c);
	}
	if(i==3)
	{
		printf("<screen video ");
	}
	if(i==4)
	{
		printf("videoData codecID=%con2 VP6%c ",c,c);
	}
	if(i==5)
	{
		printf("videoData codecID=%con2 VP6 with alpha channel%c ",c,c);
	}
	if(i==6)
	{
		printf("videoData codecID=%cscreen video vrsion 2%c ",c,c);
	}
	if(i==7)
	{
		printf("<AVC ");
	}
	else
	{
		printf("videoData codecID=%cAAC%c ",c,c);
	}
}
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
		printf("no audio tag%d\n",x);
	}
	if(x==1)
	{
		printf("audio tag are present%d\n",x);
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
		printf("no video tag%d\n",y);
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
