#include <stdio.h>
#include <stdlib.h>

struct test_struct
{
	char s1[128];
	char s2[128];
};

struct test_struct tstrings[10] = {
	{"Aura net", "Aura net" },
	{"Bangalore", "Bangalore"},
	{"India cuntry", "india cuntry"},
	{"India cuntry", "india "},
	{"India cuntry", "inDia ntry"},
	{"India cuntry", "india cuntry"},
	{"India cuntry", "iNdia try"},
	{"India cuntry", "india cuntry"},
	{"India cuntry", "India cuntry"},
	{"India cuntry", "india cuntry"}
};

int main()
{
	int len=0, i;

	for (i = 0; i < 10; i++)
	{
		printf("-->%d.%s:%s\n", i+1, tstrings[i].s1, tstrings[i].s2);
	}

	exit(1);

#if 0
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
#endif

}
