#include <stdio.h>

main()
{
	char str[10][20] = {
							"add 10 20",
							"mul 10 5",
							"sub 20 10",
							"div 10 5"
						};
	int c;
	if(str[0] == "add")
	{
		c = add(10, 20);
		printf("---> add is %d\n", c);
	}

	else if(str[1] == "mul")
	{
		c = mul(10, 5);
		printf("---> sub is %d\n", c);
	}

	else if(str[2] == "sub")
	{
		c = sub(10, 5);
		printf("---> mul is %d\n", c);
	}

	else if(str[3] == "div")
	{
		c = div(10, 5);
		printf("---> div is %d\n", c);
	}

}


int add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}

int mul(int x, int y)
{
	int z;
	z = x * y;
	return z;
}

int sub(int x, int y)
{
	int z;
	z = x - y;
	return z;
}

int div(int x, int y)
{
	int z;
	z = x % y;
	return z;
}
