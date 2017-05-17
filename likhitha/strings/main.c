#include <stdio.h>
#include "defs.h"

int main()
{
	int len=0, i, t, n ;
	char name[100]="likhitha";
	char rev[100]=" ";

	char s1[10][100] = { 
		"Aura net",
		"Bangalore",
		"India cuntry",

		"India cuntry",
		"India cuntry",
		"India cuntry",

		"India cuntry",
		"India cuntry",
		"India cuntry",
		"India cuntry"
	};

	char s2[10][100]={" "};

	char s[10][100] = { 
		"Aura net",

		"Bangalore",
		"India auntry",
		"India duntry",

		"India cuxtry",
		"Inpia cuntry",
		"Incia cuntry",

		"Incia cuntry",
		"Inxia cuntry",
		"India cuntry"
	};


	len=astrlen(name);
	printf("string length::");
	printf("length=%d\n",len);

	printf("*******\n");


	for(i=0 ; i<10 ; i++)
	{
		printf("string copy::");
		astrcpy(s2[i], s1[i]);

		printf("s1 :%s:::", s1[i]);
		printf("s2 :%s\n", s2[i]);

	}
	printf("*******\n");

	for(i=0 ;i<10 ;i++)
	{

		printf("string n copy::");
		astrncpy(s2[i], s1[i], 7);

		printf("s1 :%s:::  ", s1[i]);
		printf("s2 :%s\n", s2[i]);

	}
	printf("*******\n");

	for (i = 0; i < 10; i++)
	{
		printf("string compare::");
		t = astrcmp(s1[i], s[i]);

		printf("%s::%s -->", s1[i], s[i]);
		if(t==0)
			printf("SAME\n");
		else
			printf("NOT SAME\n");

	}

	printf("*******\n");
	for(i=0 ; i< 10 ; i++)
	{
		printf("string n compare::");
		t=astrncmp(s, s1,3);

		if(t==0)
			printf("two strings are same\n");
		else
			printf("two strings are different\n");

	}

	printf("*******\n");

	printf("string reverse::");
	astrrev(name,rev);
	printf("%s\n",name);
	printf("%s\n",rev);
}

