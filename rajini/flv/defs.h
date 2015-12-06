#include <stdbool.h>


typedef struct file_head
{
 char SIGN[10];
 int version;
 bool is_audio;
 bool is_video;
 unsigned int off_set;
}fhead;
