#include "stdio.h"

int addition(int x, int y)
{
	int c = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("x :%d\n", x);
	printf("y :%d\n", y);

	c = x + y;

	return c;
}

int substraction(int x, int y)
{
	int c = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("x :%d\n", x);
	printf("y :%d\n", y);

	c = x - y;

	return c;
}

int multiplication(int x, int y)
{
	int c = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("x :%d\n", x);
}

int division(int x, int y)
{
	int c = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("x :%d\n", x);
	printf("y :%d\n", y);

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

char test_strs[10][100] = {
	"add 10 20",
	"    add      10     20     ",
	"    Add      10     20     ",
	"    ADD      10     20     ",
	"    mul      10     20     ",
	"    MUL      10     20     ",
	"    MUL      10     20   30   ",
	"    MUL         20     ",
	"    MUlL    ",
};

int parse_arguments(char *src, char *pcmd, int *pa, int *pb)
{

}

int perform_operation(char *pcmd, int a, int b)
{
	int result = 0;

	for (i = 0; i <= 3; i++)
	{
		sope = strcmp(data_list[i].operation, cmd);
		if (sope == 0)
		{
			result = data_list[i].fp(a, b);
		}
	}
	return result;

}

main()
{
	int a = 10;
	int b = 20;
	int result = 0, i = 0;
	char cmd[100]= "sub";
	int sope = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	for (i = 0; i < sizeof(test_strs)/sizeof(test_str[i]); i++)
	{
		parse_arguments(test_strs[i], cmd, &a, &b);
		result = perform_operation(cmd, a, b);
		printf("%d and %d = %d\n", a, b, result);
	}
}
