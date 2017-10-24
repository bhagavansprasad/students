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


	for (i = 0; i < 10; i++)
	{
		len = astrlen(s1[i]);
		printf("-->\'%s\' length :%d\n", s1[i], len);
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

}
