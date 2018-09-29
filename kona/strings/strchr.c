#include <stdio.h>
#include <string.h>
main()
{
	char *p;
	p=strchr("sreenivasulareddy",'r');
	printf("%s\n",p);
	p=strrchr("sreenivasulareddy",'r');
	printf("%s\n",p);
}


