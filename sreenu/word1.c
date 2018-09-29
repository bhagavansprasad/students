#include<stdio.h>
#define MAX_COL_SIZE 100

typedef struct test_strings_t
{
	int len;
	char data[100];
}test_strings;

test_strings strs[] = { 
	{3, "       how           rr           u"},
	{3, "how rrrrrrrr uu"},
	{0, " "},
	{3, "dsfksjd kjkdsf kdshkk "}, 
	{1, "a"},
	{7, "a b c d e f"}
};

#if 0

char strings[][MAX_COL_SIZE] = {
	"       how           rr           u",
	"how rrrrrrrr uu",
	" ",
	"dsfksjd kjkdsf kdshkk ",
	"a"};
#endif

int wordcount(char p[]);

int main()
{
	int i, retval;
	for(i=0; i <= sizeof(strs)/sizeof(test_strings); i++)
	{
		retval = wordcount(strs[i].data);
		printf("%d. expretval :%d, wcount :%d, string: %s\n", i+1, strs[i].len, retval, strs[i].data);
		if (strs[i].len != retval)
		{
			printf("Function wordcount returned wrong values \n");
			printf("%d. expretval :%d, wcount :%d, string: %s\n", i+1, strs[i].len, retval, strs[i].data);
			break;
		}
	}
}

//int wordcount(char p[])
int wordcount(char *p)
{
	int i, wcount = 0;

	for(i=0;p[i]!='\0';i++)
	{
		if((p[i] != ' ' && p[i+1] == ' ') || (p[i]!=' ' && p[i+1] == '\0'))
			wcount++;
	}
	return wcount;
}
