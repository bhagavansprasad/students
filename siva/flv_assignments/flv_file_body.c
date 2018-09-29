typedef struct
{
	unsigned int previous_tag;      //It tells the total size of previous tag, or 0 for first tag
	unsigned char type;             //It determines the layout of body forexample{audio,video,metadata}
	unsigned char data_size[4];   //It tells size of body(total size - 11)
	unsigned char time_stamp[25];     //It tells Timestamp of tag in Milliseconds
	unsigned char time_stamp_extended; //Extension of timestamp
	unsigned char stream_id[25];
	}flv_tag;


#include<fcntl.h>
#include<sys/stat.h>
#include <stdio.h>
main()
{
	flv_tag tag;
	int fd,val=0;
	fd=open("sixth.flv",O_RDONLY);
	if(fd==-1)
	{
		perror("\nfile is not opened\n");
		exit(0);
	};

	read_flv_body(fd, &tag);   /*calling function flv_header*/

}
read_flv_body(int fd,flv_tag *taghead)
{
	int val=0;

	val=lseek(fd,9,SEEK_SET);

	printf("lseek value =%d\n",val);

	val=read(fd,&taghead->previous_tag,4);


	printf("previous_head=%d\n",taghead->previous_tag);

	val=read(fd,&taghead->type,1);

	printf("type=%d\n",taghead->type);

	 tag(&taghead->type);           //calling function tag

    
	val=read(fd,&taghead->data_size,3);

	taghead->data_size[4]='\0';

	char *c;int i;

	c=&taghead->data_size;
    printf("DATA_SIZE=");
	for(i=0;i<3;i++)
	{
		printf("%d",*c);
		c++;
	}
     printf("\n");

	val=read(fd,&taghead->time_stamp,3);
	taghead->time_stamp[25]='\0';
	char *t;int j;
	t=&taghead->time_stamp;
	printf("TIME_STAMP=");
	for(j=0;j<3;j++)
	{
	printf("%x",*t);
	t++;
	}
    printf("\n");
	val=read(fd,&taghead->time_stamp_extended,1);
	printf("TIME STAMP EXTENDED =%d",taghead->time_stamp_extended);
    
	printf("\n");
	val=read(fd,&taghead->stream_id,3);
    taghead->stream_id[25]='\0';
	int k;char *s;
	s=taghead->stream_id;
	printf("STREAM_ID=");
	for(k=0;k<3;k++)
	{
		printf("%X",*s);
	s++;
	}
printf("\n");

}





tag(char *tag)
{

	
	int i=3,k,l;
	k=(*tag)<<3;
	l=k>>3;
	if(l==8)
	{
		printf("AUDIO TAG HEADER\n");
	}
	if(l==9)
	{
		printf("VIDEO TAG HEADER\n");
	}
	if(l==18)
	{
		printf("SCRIPT DATA\n");
	}
}



