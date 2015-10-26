#include <stdio.h>
#include <string.h>
#include "defh.h"
main()
{
	
	char s1[]="sreeNivaSula REDdy";
	
	char s2[]="KoNa";
	char d[30];
	
	int n=3,sv,sv1,b;
	
	char *a;
	
	a=strcpy(d,s1);
	
	printf("astrcpy :%s\n",a);
	
	a=astrncpy(d,s1,n);
	
	printf("astrncpy :%s\n",a);
	
	sv=astrcmp(s1,s2);
	
	if(sv==0)
	
	
	printf("astrcmp :same\n");
	
	else
	
	printf("astrcmp :not same\n");
	
	sv1=astrncmp(s1,s2,n);
	
	if(sv1==0)
	
	printf("astrncmp :same\n");
	
	else
	
	printf("astrncmp :not same\n");
	
	b=astrlen(s1);
	
	printf("astrlen :%d\n",b);
	
	sv=astrcasecmp(s1,s2);
	
	if(sv==0)
	
	printf("astrcasecmp :same\n");
	
	else
	
	printf("astrcasecmp :not same\n");
	
	sv1=astrncasecmp(s1,s2,n);
	
	if(sv1==0)
	
	printf("astrncasecmp :same\n");
	
	else
	
	printf("astrncasecmp :not same\n");
	
	a=astrcat(s2,s1);
	
	printf("--->soure is %s\n",s1);
	
	printf("destination is %s\n",a);
	
	char *z;
	z=astrncat(s2,s1,n);
	
	printf("--->soure is %s\n",s1);
	
	printf("destination is %s\n",z);
	
	printf("the s1 string is %s\n",s1);
	
	astrlwr(s1);
	
	printf("astrlwr is %s\n",s1);
	
	astrupr(s1);
	
	printf("astrupr is %s\n",s1);
}
