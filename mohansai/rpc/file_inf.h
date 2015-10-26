typedef struct file_info_t
{
	struct data *prev;
	struct data *next;

	char file_name[25];
	int  file_desc;
	int  file_mode;
}file_info;


