
typedef struct file_info_t
{
	struct file_info_t *prev;
	struct file_info_t *next;

	char name[25];
	int descriptor;
	int mode;
	int offset;
}file_info;

int add_fcb_to_list(file_info *fcb);
file_info * fd_check(int fd);
int remove_fcb_from_list(int fd);
int update_fcb(file_info *fcb);
