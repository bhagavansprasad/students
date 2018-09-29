#include "stdio.h"

int my_function1(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int my_function2(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int my_function3(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

int my_function4(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

struct fptr_struct
{
	int (*fp)(int, char);
};

struct fptr_struct sptr[4] = {my_function1, my_function2, my_function3, my_function4}; 

main()
{
	int a = 10, ch = 'y';
	int i = 0;

	for (i = 0; i < 4; i++)
		sptr[i].fp(a, ch);
}
