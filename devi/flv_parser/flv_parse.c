#include "flv.h"

int read_flv_header(int fd, char *buff, int len)
{
	int r = 0;
	r = read(fd,buff,len);
	printf("%s\n",buff);
	return r;
}

void parse_flv_header(char *buff, int len, struct flv_file_header *phead)
{
	unsigned char flags = 0;
	unsigned int mask = 1,i,n, offset = 0;

	bzero(phead, sizeof(struct flv_file_header));
	strncpy(phead->signature, buff, SIGNATURE_LEN);
	phead->version = buff[3];
	flags = buff[4];

	phead->is_video = ((flags&(mask<<0))?1:0);
	phead->is_audio = ((flags&(mask<<2))?1:0);
	for(i = 5; i <= 8; i++)
	{
		n = buff[i];
		offset+= offset_value(n);
	}
	phead->offset = offset;
}

void dump_flv_header(struct flv_file_header *phead)
{

	printf("SIGNATURE ----- %s\n",phead->signature);
	printf("VERSION   ----- %d\n",phead->version);
	if(1 == phead->is_audio)
	{
		printf("AUDIO     ----- audio tags are present\n");
	}
	else 
		printf("AUDIO     ----- audio tags are not present\n");
	if(1 == phead->is_video)
	{
		printf("VIDEO     ----- video tags are present\n");
	}
	else
		printf("VIDEO     ----- video tags are not present\n");
	printf("OFFSET    ----- %d\n\n\n",phead->offset);
}

void parse_flv_tag(char *buff, int len, struct flv_tag *thead)
{

	int i=0,j;
	unsigned int n=0,res=0;
	
	bzero(thead, sizeof(struct flv_tag));
	
	for(i=3;i>=0;i--)
	{
		n+=convert_hex_to_dec(buff[i]);
	}	
	thead->prev_tag_size = n;
	set_power();
	n=0;
	n=convert_hex_to_dec(buff[4]);
	if(n == audio)
	thead->t=n;

	else if(n == video)
	{
		thead->t=n;
		
		thead->frametype = (buff[15]&0xf0)>>4;
	}

	else if(n == script)
	thead->t=n;

	set_power();
	n=0;
	for(i=7;i>=5;i--)
	{
		n+=convert_hex_to_dec(buff[i]);
	}
			
	thead->data_size=n;
	
	set_power();

	n=0;
	for(i=10;i>=8;i--)
	{
		n+=convert_hex_to_dec(buff[i]);
	}		

	thead->time_stamp = n;
	
	set_power();


	n=buff[11];
	thead->time_stamp_extended = n;
	
	n=0;
	for(i=14;i>=12;i--)
	{
		n+=convert_hex_to_dec(buff[i]);
	}		

	thead->streamID = n;
	set_power();

}

void dump_flv_tag(struct flv_tag *thead)
{

	printf("Prev_tag_size         ----- %d\n",thead->prev_tag_size);
	printf("Tag_type              ----- %d\n",thead->t);
	printf("Data_size             ----- %d\n",thead->data_size);
	printf("Time_stamp            ----- %d\n",thead->time_stamp);
	printf("Time_stamp_extended   ----- %d\n",thead->time_stamp_extended);
	printf("stream ID             ----- %d\n",thead->streamID);
	printf("frametype             ----- %d\n",thead->frametype);
}


