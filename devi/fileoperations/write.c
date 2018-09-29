#include <stdio.h>
#include <fcntl.h>
main()
{
	char str[] = "devi\travi\n";
	write(1,str,sizeof(str));
}
