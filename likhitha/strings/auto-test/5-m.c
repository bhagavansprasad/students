#include <stdio.h>
#include <stdlib.h>

struct test_struct
{
	char s1[128];
	int s1len;
	char s2[128];
	int s2len;
};

struct test_struct tstrings[ ] = {
	{"Aura net", 8, "Aura net", 8 				},
	{"Bangalore", 9, "Bangalore", 9             },
	{"India cuntry", 12,  "india cuntry", 12	},
	{"India cuntry", 12, "india ", 6			},
	{"India cuntry", 12, "inDia ntry", 10		},
	{"India cuntry", 12, "india cuntry", 12		},
	{"India cuntry", 12, "iNdia try", 9			},
	{"India cuntry", 12, "india cuntry", 12		},
	{"India cuntry", 14, "indiacuntry",11		},
	{" ", 1, "indiacuntry", 11					}
};

//len2 = astrlen(tstrings[i].s2);
//printf("-->%d.%s:%d\t%s:%d\n", i+1, tstrings[i].s1, len1, tstrings[i].s2, len2);
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
		printf("-->%d.%s:%d\t", i+1, tstrings[i].s1, len1);

		if (tstrings[i].s1len == len1)
			printf("VALID length\n");
		else
			printf("INVALID length, expecting :%d got :%d\n", tstrings[i].s1len, len1);
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
