#include "file_inf.h"

int sys_open(char *filename, int mode);
int sys_read(int fd, char *rbuff, int len, file_info *fcb);
int sys_write(int fd, char *rbuff, int len);
int sys_close(int fd);
