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

main()
{
	int a = 10;
	int b = 20;
	int result = 0, i = 0;
	char cmd[100]= "sub";
	int sope = 0;

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	for (i = 0; i <= 3; i++)
	{
		sope = strcmp(data_list[i].operation, cmd);
		if (sope == 0)
		{
			result = data_list[i].fp(a, b);
			printf("%d and %d = %d\n", a, b, result);
		}
	}
}
