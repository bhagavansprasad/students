#include "stdio.h"

int llheader = 100;

int dump_glob_data(void)
{
	printf("gdata :%d\n", llheader);
}

int main()
{
	dump_glob_data();
}
