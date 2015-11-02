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
	dump_flv_header(phead);
	strncpy(phead->signature, buff, SIGNATURE_LEN);
	phead->version = buff[3];
	flags = buff[4];

	phead->is_video = ((flags&(mask<<0))?1:0);
//	mask = 1;
	phead->is_audio = ((flags&(mask<<2))?1:0);
	for(i = 5; i <= 8; i++)
	{
		n = buff[i];
		offset+= offset_value(n);
	}
	phead->offset = offset;

	printf("buff[0]-->%c\n",buff[0]);

	printf("buff[0]-->%c\n",buff[1]);
	printf("buff[0]-->%c\n",buff[2]);
	printf("buff[0]-->%c\n",buff[3]);
	printf("buff[0]-->%c\n",buff[4]);
	printf("buff[0]-->%c\n",buff[5]);
	printf("buff[0]-->%c\n",buff[6]);
	printf("buff[0]-->%c\n",buff[7]);
	printf("buff[0]-->%c\n",buff[8]);


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
	/*unsigned char flags = 0;
	
	unsigned int n; 

	unsigned int i,converted_val=0,j; 
	int k;

	bzero(thead, sizeof(struct flv_tag));
	dump_flv_tag(thead);
	for(i = 0; i <12; i++)
	{	
		n = buff[i];
		//printf("n -- %d\n",n);
		converted_val+= n;
	}
	thead->prev_tag_size = converted_val;
	//converted_val = 0;
	n= buff[4];
	printf("n -- %d\n",n);
	//converted_val = offset_value(n);
	if(n == audio)
	thead->t = audio;
	else if(n == video)
	thead->t = video;
	else if(n == script)
	thead->t = script;

	converted_val = 0;

	for(j=8;j>=6;j--)
	{
		n = buff[j];
		printf("%d\n",n);
		converted_val+= n;//offset_value(n);
	}
	thead->data_size = converted_val;*/
	int i=0;
	unsigned int n=0,res=0;
	printf("buff[0]-->%c\n",buff[0]);
	printf("buff[0]-->%c\n",buff[1]);
	printf("buff[0]-->%c\n",buff[2]);
	printf("buff[0]-->%c\n",buff[3]);
	printf("buff[0]-->%c\n",buff[4]);
	printf("buff[0]-->%c\n",buff[5]);
	printf("buff[0]-->%c\n",buff[6]);
	printf("buff[0]-->%c\n",buff[7]);
	printf("buff[0]-->%c\n",buff[8]);
	printf("buff[0]-->%c\n",buff[9]);
	printf("buff[0]-->%c\n",buff[10]);
	printf("buff[0]-->%c\n",buff[11]);
	
	//for(i=0;i<4;i++)
	//{
	n=buff[0]+buff[1]+buff[2]+buff[3];
	printf("n--%d\n",n);
	thead->prev_tag_size = n;
	n=buff[4];
	printf("n--%d\n",n);
	thead->t=n;
	n=buff[5]+buff[6]+buff[7];
	printf("n--%X\n",n);
	for(i=7;i>=5;i--)
	{
	res = res+convert_hex_to_bin(buff[i]);
	printf("res-- %d\n",res);
	}
	thead->data_size=res;
	
	n=buff[8]+buff[9]+buff[10];
	printf("n--%d\n",n);
	thead->time_stamp = n;

	
	n=buff[11];
	printf("n--%d\n",n);
	thead->time_stamp_extended = n;
}

void dump_flv_tag(struct flv_tag *thead)
{

	printf("Prev_tag_size         ----- %d\n",thead->prev_tag_size);
	printf("Tag_type              ----- %d\n",thead->t);
	printf("Data_size             ----- %d\n",thead->data_size);
	printf("Time_stamp            ----- %d\n",thead->time_stamp);
	printf("Time_stamp_extended   ----- %d\n",thead->time_stamp_extended);
}
