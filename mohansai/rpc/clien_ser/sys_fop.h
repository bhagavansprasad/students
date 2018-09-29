#include "file_db.h"

int sys_open(char *filename, int mode);
int sys_read( char *rbuff, int len, file_info *fcb);
int sys_write( char *rbuff, int len,file_info *fcb);
int sys_close(int fd);
