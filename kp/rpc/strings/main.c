#include<stdio.h>
#include<string.h>

typedef struct data_strings_t
{
	char s1[1000];
	char s2[1000];
}data_strings;

data_strings  strs[100] = {
	{"hello", "hello"},
	{"hello", "helloooo"},
	{"Hello", "HeLlo"},
	{"Hello", "Hello"},
	{"helloooooo", "hello"},
	{"how are you","HOW are YOU"}
};

main()
{
	int i =0;

	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d. %s<-->%s\n", i, strs[i].s1, strs[i].s2);
	//}

	for (i = 0; i < 7; i++)
	{
		printf("%d. %s<-->%s --->", i, strs[i].s1, strs[i].s2);
		if (astrcasecmp(strs[i].s1, strs[i].s2) == 1)
			printf("the string are same\n");
		else
			printf("the strings are not same\n");
	}
}
