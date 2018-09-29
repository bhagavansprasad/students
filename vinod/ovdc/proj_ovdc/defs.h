#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <signal.h>
#include <dirent.h>
#define BUFF_SIZE 1000

struct pidstatus
{        
	int pid;
	int rpid;
	int jiffy;
}data1, data2;

int get_proc_list(int *ptr);
int get_jiffy(int fd);
int get_fd(int pid);
void ctrlmsg(int val, int pid);
void change_priority(int pid, int priority);
void ovd(int fdw);
void ovc(int fdr);
