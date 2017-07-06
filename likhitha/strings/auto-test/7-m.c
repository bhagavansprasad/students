#include <stdio.h>
#include <stdlib.h>

struct test_struct
{
	char s1[128];
	int s1len;
	char s2[128];
	int s2len;
	int is_same;
};

struct test_struct tstrings[ ] = {
	{"Aura net", 8, "Aura net", 			8,  0 		},
	{"Bangalore", 9, "Bangalore", 			9,  0       },
	{"India cuntry", 12,  "india cuntry", 	12, 1		},
	{"India cuntry", 12, "india ", 			6,	1		},
	{"India cuntry", 12, "inDia ntry", 		10, 1		},
	{"India cuntry", 12, "india cuntry", 	12, 1		},
	{"India cuntry", 12, "iNdia try", 		9,  1		},
	{"India cuntry", 12, "india cuntry", 	12, 1		},
	{"India cuntry", 14, "indiacuntry",		11, 1		},
	{"test", 1, "indiacuntry", 				11, 0		}
};

//len2 = astrlen(tstrings[i].s2);
//printf("-->%d.%s:%d\t%s:%d\n", i+1, tstrings[i].s1, len1, tstrings[i].s2, len2);
int main()
{
	int len1=0, len2 = 0, retval = 0, i;
	int elem_count = 0;

	elem_count = sizeof(tstrings)/sizeof(tstrings[0]);
	for (i = 0; i < elem_count; i++)
	{
		printf("-->%d.%s:%s\n", i+1, tstrings[i].s1, tstrings[i].s2);
	}

	for (i = 0; i < elem_count; i++)
	{
		len1 = astrlen(tstrings[i].s1);
		printf("-->%d.%s:%d\t", i+1, tstrings[i].s1, len1);
		if (tstrings[i].s1len == len1)
			printf("VALID length\n");
		else
			printf("INVALID length, expecting :%d got :%d\n", tstrings[i].s1len, len1);

		len2 = astrlen(tstrings[i].s2);
		printf("-->%d.%s:%d\t", i+1, tstrings[i].s2, len2);
		if (tstrings[i].s2len == len2)
			printf("VALID length\n");
		else
			printf("INVALID length, expecting :%d got :%d\n", tstrings[i].s2len, len2);
	}

	for (i = 0; i < elem_count; i++)
	{
		retval = astrcmp(tstrings[i].s1, tstrings[i].s2);

		if (retval != tstrings[i].is_same)
			printf("-->%d. TEST failed expected :%d, returned :%d,%s:%s\n", i+1, tstrings[i].is_same, retval, tstrings[i].s1, tstrings[i].s2); 
	}
}
