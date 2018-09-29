#include "stdio.h"

struct fptr_struct
{
	int (*fp)(int, char);
};

struct fptr_struct sptr;

main()
{
	int a = 10, ch = 'y';

	my_function(a, ch);

	//fp = my_function;
	sptr.fp = my_function; //assinging the pointer

	//fp(a, ch);
	sptr.fp(a, ch); //calling the function
}
