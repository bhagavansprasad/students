#include <stdio.h>
#include <string.h>

int addition(int x, int y);
int subtraction(int x, int y);
int multiplication(int x, int y);
int division(int x, int y);

struct fptr
{
	char cmnd[10];
	int (*fp)(int, int);
};

int main(int argc, char *argv[])
{
	int i, val=0, retval=0;
	int a=0, b=0;

	struct fptr data[4] = { 
	{"add", addition},
	{"sub", subtraction},
	{"mul", multiplication},
	{"div",	division}
	};

	a = atoi(argv[2]);
	b = atoi(argv[3]);

	printf("a -> %d\nb -> %d\n", a, b);

	for(i=0 ; i<4 ; i++)
	{
		if(strcmp(data[i].cmnd, argv[1]) == 0)
		{
			val = data[i].fp(a,b);
			printf("%s -> %3d , %3d = %3d\n", argv[1], a, b, val);
		}	
	}
	return 0;
}

int addition(int x, int y)
{
	return x+y;
}

int subtraction(int x, int y)
{
	return x-y;
}
int multiplication(int x, int y)
{
	return x*y;
}
int division(int x, int y)
{
	return x/y;
}
