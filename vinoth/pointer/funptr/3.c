
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

#if 0
	sptr[0].fp = my_function1;
	sptr[1].fp = my_function2;
	sptr[2].fp = my_function3;
	sptr[3].fp = my_function4;
#endif

	sptr[0].fp(a, ch);
	sptr[1].fp(a, ch);
	sptr[2].fp(a, ch);
	sptr[3].fp(a, ch);
}
