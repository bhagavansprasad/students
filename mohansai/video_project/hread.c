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
	
	int i;
	FILE *fp;
	
	struct header h1;
	struct records r1;


	fp=fopen("data.txt","r");
	
	if(fp==NULL)
	{
		perror("there id no content in the file");
		exit(1);
	}
	
	i=fread(&h1,sizeof(struct header),1,fp);	
	printf("i-->%d\n\r",i);
	
	printf("header:-%d\trecord:-%d\tno_of_fields:-%d\tfirst_fiels:-%d\tsecond_field:-%d\tthird field :-%d\n\r",h1.header,h1.record,h1.no_of_fields,h1.first_field,h1.second_field,h1.third_field);

	i=fread(&r1,sizeof(struct records),1,fp);	
	printf("i-->%d\n\r",i);

	printf("video:- %d\t audio:-%d \t\n\r",r1.video,r1.audio);
}



