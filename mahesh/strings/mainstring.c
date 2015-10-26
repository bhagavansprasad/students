#include <stdio.h>
#include"defs.h"
main()
{
	char s1[]="auRA net";
	char s2[]="hello";
	char d[20];
	int n=4,rv,rv2,b;
	char *a;

	a = astrcpy(d,s1);

	printf("strcpy : %s\n",a);

	a = astrncpy(d,s1,n);

	printf("strncpy : %s\n",a);	

	rv = astrcmp(s1,s2);

	if( rv == 0 )

		printf("strcmp : same\n"); 

	else

		printf(" strcmp : nt same\n");

	rv2 = astrncmp(s1,s2,n);

	if( rv2 == 0 )

		printf(" strncmp : same\n");

	else

		printf(" strncmp : nt same\n");

	b = astrlen(s1);

	printf(" strlen : %d\n",b);

	rv = astrcasecmp(s1,s2);

	printf("astrcasecmp : ");

	if (rv == 0 )

		printf("same\n");

	else

		printf("not same\n");

	rv=astrncasecmp(s1,s2,n);

	printf("astrncasecmp : ");

	if( rv == 0 )

		printf("same\n"); 

	else

		printf("not same\n");

	printf("before\n");

	printf("----->source : %s\n",s1);

	printf("----->destination : %s\n",s2);

	a = astrcat(s2,s1);

	printf("after astrcat\n");

	printf("----->source : %s\n",s1);

	printf("----->destination : %s\n",a);

		
	char *z;

	z = astrncat(s2,s1,n);

	printf("after astrncat\n");

	printf("----->source : %s\n",s1);

	printf("----->destination : %s\n",z);

	printf("given string : %s\n",s1);

	astrlwr(s1);

	printf("astrlwr : %s\n",s1);

	astrupr(s1);

	printf("astrupr : %s\n",s1);

}
