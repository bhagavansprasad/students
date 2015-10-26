#include <sys/types.h>
#include <unistd.h>
int rpcc_open(char *, int, int);
int rpcc_read(int, char *, int);
int rpcc_write(int,char *, int);
int rpcc_lseek(int, off_t, int);
int rpcc_close(int);
int rpcc_get_first();
int rpcc_get_prev(int);
int rpcc_get_next(int);
int rpcc_get_last();
int rpcc_get_fact(int, int, int);
