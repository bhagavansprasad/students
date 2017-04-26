#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int addition(int x, int y)
{
	int c = 0;

	//printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->x :%d\n", x);
	printf("-->y :%d\n", y);

	c = x + y;

	return c;
}

int substraction(int x, int y)
{
	int c = 0;

	//printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->x :%d\n", x);
	printf("-->y :%d\n", y);

	c = x - y;

	return c;
}

int multiplication(int x, int y)
{
	int c = 0;

	//printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->x :%d\n", x);
	printf("-->y :%d\n", y);

	c = x * y;

	return c;
}

int division(int x, int y)
{
	int c = 0;

	//printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->x :%d\n", x);
	printf("-->y :%d\n", y);

	c = x % y;

	return c;
}

struct fun_data
{
	char operation[64];
	int (*fp)(int, int);
};

struct fun_data data_list[4] = {
	{ "add", addition },
	{ "sub", substraction },
	{ "mul", multiplication },
	{ "div", division }
};

struct fun_data test_list[10] = {
	{ "add", addition },
	{ "ADD", addition },
	{ "Add", addition },
	{ "sub", substraction },
	{ "mul", multiplication },
	{ "MUL", multiplication },
	{ "MUlL", multiplication },
	{ "div", division }
};

char test_strs[10][100] = {
	"add 10 20",
	"    add      20     20     ",
	"    Add      10     20     ",
	"    ADD      10     20     ",
	"    mul      10     20     ",
	"    MUL      10     20     ",
	"    MUL      10     20   30   ",
	"    MUL         20     ",
	"    MUi    ",
	"    div    10    20"
};

int parse_arguments(char *src, char *pcmd, int *pa, int *pb)
{
	int i = 0, j = 0;
	char s[10];

	for(i = 0 ; src[i] == ' ' && src[i] != '\0'; i++);

	for( ; src[i] != ' ' && src[i] != '\0'; i++, j++)
	{
		s[j] = src[i];
	}
	strcpy(pcmd , s);
	pcmd[j] = '\0';
	printf("--> pcmd : %s\n", pcmd);

	for(; src[i] == ' ' && src[i] != '\0'; i++);

	for(j = 0 ; src[i] != ' ' && src[i] != '\0'; i++, j++)
	{
		s[j] = src[i];
	}
	pa = (int)atoi(s);
	printf("--> pa :%d\n", pa);

	for(; src[i] == ' ' && src[i] != '\0'; i++);

	for(j = 0 ; src[i] != ' ' && src[i] != '\0'; i++, j++)
	{
		s[j] = src[i];
	}
	pb = (int)atoi(s);
	printf("--> pb :%d\n", pb);
}

int perform_operation(char *pcmd, int a, int b)
{
	int i, sope = 0, result = 0;

	for (i = 0; i < sizeof(test_strs)/sizeof(test_strs[i]); i++)
	{
		sope = strcmp(test_list[i].operation, pcmd);
		if (sope == 0)
		{
			result = test_list[i].fp(a, b);
		}
	}
	return result;
}

main()
{
	int a = 10;
	int b = 20;
	int result = 0, i = 0;
	char cmd[100];
	int sope = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	for (i = 0; i < sizeof(test_strs)/sizeof(test_strs[i]); i++)
	{
		parse_arguments(test_strs[i], cmd, &a, &b);
		result = perform_operation(cmd, a, b);
		printf("%d and %d = %d\n\n", a, b, result);
	}
}
