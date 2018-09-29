#include <stdio.h>
int main()
{
	int len=0, i, t, n;
	char name[11]="likhithamg";

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
	printf("%d\n",len);

	for(i=0 ; i<10 ; i++)
	{
		astrcpy(s2[i], s1[i]);
		printf("s1 :%s\n", s1[i]);
		printf("s2 :%s\n", s2[i]);
	}

	for(i=0 ;i<10 ;i++)
	{
		astrncpy(s2[i], s1[i], 7);
		printf("s1 :%s  ", s1[i]);
		printf("s2 :%s\n", s2[i]);
	}

	for (i = 0; i < 10; i++)
	{
		t = astrcmp(s1[i], s[i]);

		printf("%s::%s -->", s1[i], s[i]);
		if(t==0)
			printf("SAME\n");
		else
			printf("NOT SAME\n");
	}

	for(i=0 ; i< 10 ; i++)
	{
		t=astrncmp(s, s1,3);
		if(t==0)
			printf("two strings are same\n");
		else
			printf("two strings are different\n");
	}
}
