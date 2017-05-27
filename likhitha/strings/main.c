#include <stdio.h>
int main()
{
	int len=0, i, t, n ;

	char name[100]="likhitha";
	char rev[100]=" ";


	char s1[10][100] = { 
		"Auranet",
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

	char s[10][100]={" "};

	char s2[10][100] = { 
		"Auranet",

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
		astrcpy(s[i], s1[i]);

		printf("s1 :%s:::", s1[i]);
		printf("s2 :%s\n", s[i]);

	}
	printf("*******\n");


	for(i=0 ;i<10 ;i++)
	{
		printf("string n copy::");
		astrncpy(s[i], s1[i], 7);
		printf("s1 :%s:::  ", s1[i]);
		printf("s2 :%s\n", s[i]);
	}
	printf("*******\n");



	for (i = 0; i < 10; i++)
	{
		printf("string compare::");
		t = astrcmp(s1[i], s2[i]);

		printf("%s::%s -->", s1[i], s2[i]);
		if(t==0)
			printf("SAME\n");
		else
			printf("NOT SAME\n");
	}
	printf("*******\n");


	for(i=0 ; i< 10 ; i++)
	{
		printf("string n compare::");
		t=astrncmp(s2, s1,3);
		if(t==0)
			printf("two strings are same\n");
		else
			printf("two strings are different\n");
	}
	printf("*******\n")
		;



	printf("string concat::\n");
	for(i=0 ; i<10 ; i++)
	{
		astrcat(s2[i],s1[i]);
		printf(" %s ",s1[i]); 
		printf("\n");
	}
	printf("*******\n");



	printf("string casecmp::\n");
	for(i=0 ; i<10 ; i++)
	{
		t=astrcasecmp(s1,s);

		if(t==0)
			printf("two strings are equal\n");
		else
			printf("two strings are not equal\n");
	}
	printf("*******\n");

}
