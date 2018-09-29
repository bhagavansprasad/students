#include <stdio.h>
#include"astrcpy_def.h"
main()
{
	char s1[]="aura net";
	char s2[]="aura ne";
	char d[20];
	int n=4,rv,rv2;
	char *a;
	a=astrcpy(d,s1);
	printf("%s\n",a);
		a=astrncpy(d,s1,n);
	printf("%s\n",a);	
	rv =astrcmp(s1,s2);
	if(rv==0)
	 printf("same\n");
	else
	 printf("nt same\n");
	 rv2 =astrncmp(s1,s2,n);

	 	if(rv2==0)
	 printf("same\n");
	else
	 printf("nt same\n");

}
