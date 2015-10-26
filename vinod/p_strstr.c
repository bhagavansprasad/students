#include "stdio.h"
#include "a_string.h"
int main()
{
	char a[]="aura networks bangalore india",b[]="india";
	char *p;
	p=a_strstr(a,b);
	if(p)
		printf("The substring \"%s\" found in \"%s\" at \"%s\"\n",b,a,p);
	else
		printf("The substring \"%s\" not found in \"%s\"\n",b,a);
	return 0;
}
