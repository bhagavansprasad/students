#include <stdio.h>
#include <stdlib.h>

main()
{
	int x=0,x1=0,x2=0,y=0,y1=0,z=0,z1=0,n=7;
	char s1[50]= "aura netwok";
	char s2[50]= "aura netwok bangalore";
	char d[50];

	x=astrlen(s1);		 																	//1
	printf("The string %s, len is :%d\n", s1, x);

	printf("\n");

	printf("Before strcpy s1:%s, and d:%s\n",s1, d);
	astrcpy(d,s1);																		//2
	printf("After  strcpy s1:%s, and d:%s\n",s1, d);

	printf("\n");

	printf("Before strncpy s1:%s, and d:%s, and n:%d\n", s1, d, n);
	y=astrncpy(d,s1,n); 																	//3
	printf("After  strncpy s1:%s, and d:%s, and n:%d\n", s1, d, n);

	printf("\n");

	y1=astrcmp(s1,s2);																			//4
	if(y1==1)
		printf("same :%s :%s\n",s1,s2);
	else
		printf("not same :%s :%s\n",s1,s2);

	printf("\n");
	
	z=astrncmp(s1,s2,n);																	//5
	if(z==1)
		printf("nth str same :%s :%s :%d\n",s1,s2,n);
	else
		printf("nth str not same :%s :%s :%d\n",s1,s2,n);

	printf("\n");
	
	astrcat(s1,s2);																			//6
	printf("\nThe concatenate string is :%s\nSource string is :%s\n",s1,s2);

	printf("\n");

	z1=astrncat(s1,s2,n);																	//7
	printf("\nThe concatenate string is :%s\nSource string is :%s :%d\n\n",s1,s2,n);

	x1=astrcasecmp(s1,s2);																	//8
	if(x1==1)
		printf("same :%s :%s\n\n",s1,s2);
	else
		printf("not same :%s :%s\n\n",s1,s2);

	x2=astrncasecmp(s1,s2,n);																	//9
	if(x2==1)
		printf("same :%s :%s\n\n",s1,s2);
	else
		printf("not same :%s :%s\n\n",s1,s2);

	atolower(s1);																		//10
	printf("given string changed lower:%s",s1);

	atoupper(s1);																		//11
	printf("given string changed upper :%s",s1);
}
