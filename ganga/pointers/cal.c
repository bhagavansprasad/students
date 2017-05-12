#include <stdio.h>
#include <string.h>

char str[10][20] = {
	"add 10 20",
	"mul 10 20",
	"sub 20 10",
	"div 20 10"
};

int parse_calc_cmd(char *str, char *cmd, int *pa, int *pb)
{
	int i, j = 0;
	char s[20];
	printf("Str: %s\n", str);
	for( i = 0; i < 3; i++)
	{
		cmd[i] = str[i];
	}
	cmd[i] = '\0';
	printf ("cmd :%s\n", cmd);

	for( i = 4; i < 6; i++)
	{	
		s[j] = str[i];
		j++;
			//pa[j] = str[i] - '0';
			//printf("pa :%d\n", pa[j]);
	}
	pa = atoi(s);
	printf("pa :%d\n", pa);  

	for( i = 7; i < 9; i++)
	{ 
		j = 0;
		s[j] = str[i];
		printf("s[j] :%d\n", s[j]);
		j++;
	}
	pb = atoi(s);
	printf("pb :%d\n", pb);
}

int caliculator(char *str)
{
	char cmd[100];
	int a = 0, b = 0, c;

	parse_calc_cmd(str, cmd, &a, &b);
	printf ("cmd :%s\n", cmd);
	printf ("a   :%d\n", a);
	printf ("b   :%d\n", b);

	if(strcmp(cmd , "add") == 0)
	{
		c = add(a, b);
		printf("---> add is %d\n", c);
	}
	else if(strcmp(cmd , "mul") == 0)
	{
		c = mul(a, b);
		printf("---> mul is %d\n", c);
	}
	else if(strcmp(cmd , "sub") == 0)
	{
		c = sub(a, b);
		printf("---> sub is %d\n", c);
	}
	else if(strcmp(cmd , "div") == 0)
	{
		c = div(a, b);
		printf("---> div is %d\n", c);
	}
}

main()
{
	int i,c;
	caliculator(str[0]);
/*
	for (i = 0; i < 4; i++)
	{
		caliculator(str[i]);
	}*/
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
