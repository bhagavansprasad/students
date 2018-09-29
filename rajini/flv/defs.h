#include <stdbool.h>

<<<<<<< HEAD

typedef struct file_head
{
 char SIGN[10];
 int version;
 bool is_audio;
 bool is_video;
 unsigned int off_set;
}fhead;
=======
typedef struct file_head
{
	char signature[10];
	int version;
	bool is_audio;
	bool is_video;
	unsigned int off_set;
}fhead;

typedef struct file_tag
{
	unsigned int prev_tag;
	enum tag{
		audio=8,
		video=9,
		scriptdata=18
	}tag_type;
	unsigned int data_size;
	unsigned int time_stamp;
	unsigned int time_stampext;
	unsigned int streamID;
}thead;

int read_file_head(int fd,unsigned char *buff,int len);
void parsing_flv_head(unsigned char *buff,int len,struct file_head *fhead);
void dump_list(struct file_head *fhead);

int read_tag_head(int fd,unsigned char *buff,int len);
void parsing_tag_head(unsigned char *buff,int len,struct file_tag *thead);
void dump_tag_list(struct file_tag *thead);
>>>>>>> 20d0cfd64d72678856fd795924cc44b2e7c782f4
