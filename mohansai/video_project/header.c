#include "stdio.h"
#include "stdlib.h"

struct header
{
	int header;
	int record;
	int no_of_fields;
	int first_field;
	int second_field;
	int third_field;
};
struct records
{
	int video;
	char name[100];
	int audio;
};

main()
{
	FILE *fp;
	int i;
	struct header h1 = {sizeof(struct header),sizeof(struct records),3,4,100,4};

	struct records r1 = {1024,"mohansai",300};

	fp=fopen("data.txt","w");

	if(fp==NULL)
	{
		perror("error in open a file ");	
		exit(1);
	}

	printf("header-->%d \r\nrecord--> %d \r\nno_of_fields--> %d\r\nfirst_fiels--> %d\nsecond_field--> %d\n\r",h1.header,h1.record,h1.no_of_fields,h1.first_field,h1.second_field);

	printf("video--> %d audio--> %d  name--> %s\n\r",r1.video,r1.audio,r1.name);

		
	i=fwrite(&h1,sizeof(struct header),1,fp);
	printf("i-->%d\n\r",i);
	
	i=fwrite(&r1,sizeof(struct records),1,fp);
	printf("i-->%d\n\r",i);
}


