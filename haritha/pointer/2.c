#include <stdio.h>
main()
{
	int a=0x12131415,t;
char *cp=(char *)&a;
t=cp+1;
cp+1=cp;
cp=t;


	printf("%x%x",*cp,*cp);

	
}
