#include <stdio.h>
#include <stdlib.h>

struct test_struct
{
	char s1[128];
	char s2[128];
};

struct test_struct tstrings[ ] = {
	{"Aura net", "Aura net" },
	{"Bangalore", "Bangalore"},
	{"India cuntry", "india cuntry"},
	{"India cuntry", "india "},
	{"India cuntry", "inDia ntry"},
	{"India cuntry", "india cuntry"},
	{"India cuntry", "iNdia try"},
	{"India cuntry", "india cuntry"},
	{"India cuntry", "indiacuntry"}
};

int main()
{
	int len1=0, len2 = 0, i;
	int elem_count = 0;

	elem_count = sizeof(tstrings)/sizeof(tstrings[0]);
	for (i = 0; i < elem_count; i++)
	{
		printf("-->%d.%s:%s\n", i+1, tstrings[i].s1, tstrings[i].s2);
	}


	for (i = 0; i < elem_count; i++)
	{
		len1 = astrlen(tstrings[i].s1);
		//len2 = astrlen(tstrings[i].s2);
		//printf("-->%d.%s:%d\t%s:%d\n", i+1, tstrings[i].s1, len1, tstrings[i].s2, len2);
		printf("-->%d.%s:%d\n", i+1, tstrings[i].s1, len1);
	}

#if 0
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
