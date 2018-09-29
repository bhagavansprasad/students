#include "stdio.h"

int addtion(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int subtraction(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int multiplication(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int division(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int modulos(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}


struct fptr_struct
{
	char cmd[10];
	int (*fp)(int, char);
};

struct fptr_struct sptr[5] = {
	{ "add", addtion},
	{ "sub", subtraction},
	{ "mul", multiplication},
	{ "div", division},
	{ "mod", modulos}
}; 

main()
{
	int a = 10, ch = 'y';
	int i = 0;
	char command[10] = "mod";

	for (i = 0; i < 5; i++)
	{
		if(strcmp(sptr[i].cmd, command) == 0)
			sptr[i].fp(a, ch);
	}
}
