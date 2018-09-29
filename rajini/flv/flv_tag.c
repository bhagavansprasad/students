#include "defs.h"
#include "stdio.h"


int read_tag_head(int fd,unsigned char *buff, int len)
{
	int retval = 0;

	retval = read(fd, buff, len);

	return retval;
}

/*int get_4byte_integer(char *buff)
{
}

int get_3byte_integer(char *buff)
{
}
*/

void parsing_tag_head(unsigned char *buff,int len,struct file_tag *thead)
{
	int bits=0,i=0,b=0,c=0,d=0,e=0;

	for(bits=24,i=0 ;i<4;i++,bits-=8)
	{
		b += (buff[i] << bits);
	}
	thead->prev_tag=b;
	//thead->prev_tag= get_4byte_int(buff);

	thead->tag_type = buff[4];

	for(bits=16,i=5 ;i<8;i++,bits-=8)
	{
		c+= (buff[i]<<bits);
	}

	thead->data_size=c;
	//thead->data_size=get_3byte_int(&buff[i]);

	for(bits=16,i=8 ;i<11;i++,bits-=8)
	{
		d+= (buff[i]<<bits);
	}
	thead->time_stamp=d;
	
	thead->time_stampext=buff[11];
	//thead->time_stampext=get_3byte_int(&buff[11]);

	for(bits=16,i=12 ;i<15;i++,bits-=8)
	{
		e+= (buff[i]<<bits);
	}
	thead->streamID = e;
	//thead->streamID = get_3byte_int(&buff[i]);

}
void dump_tag_list(struct file_tag *thead)
{
	printf("prev tag size :%d\n", thead->prev_tag);


	if(thead->tag_type == 8)
	{
		printf("tag type :%d (audio)\n",thead->tag_type);
	}
	else if(thead->tag_type == 9)
	{
		printf("tag type :%d (video)\n",thead->tag_type);
	}
	else if(thead->tag_type == 18)
	{
		printf("tag type :%d (script)\n",thead->tag_type);
	}
	printf("data size     :%d\n", thead->data_size);
	printf("time stamp    :%d\n", thead->time_stamp);
	printf("time stampext :%d\n", thead->time_stampext);
	printf("stream ID     :%d\n\n", thead->streamID);
}
