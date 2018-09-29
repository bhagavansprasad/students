#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int x;
	
	char b[10]="123d4";
	x = atoi(b);
	printf("%d\n",x);
}


