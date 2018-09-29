#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
typedef struct list_t
{
	int pid;
	int giffy;
}list;

int statistics(int );
int ovd(int );
int ovc(int ); 
int get_giffys(char *);
int aatoi(char *);

