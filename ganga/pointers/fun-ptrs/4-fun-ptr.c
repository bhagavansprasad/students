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
	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	return 0;
}

int multiplication(int x, int y)
{
	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	return 0;
}

int division(int x, int y)
{
	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	return 0;
}


struct fun_data
{
	int (*fp)(int, int);
};

main()
{
	int a = 10;
	int b = 20;
	int result = 0, i = 0;
	struct fun_data fdata[4];
	//int (*fp[4])(int, int);

	printf("%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	fdata[0].fp = addition;
	fdata[1].fp = substraction;
	fdata[2].fp = multiplication;
	fdata[3].fp = division;

	for (i = 0; i <= 3; i++)
	{
		result = fdata[i].fp(a, b);
		printf("%d + %d = %d\n", a, b, result);
	}
}
