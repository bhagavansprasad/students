#include <stdio.h>
int atoi(char []);
int main()
{
	char a[100] = "12";
	int n;
	n = atoi(a);
	printf("String  = %s\nInteger = %d\n", a, n);
	return 0;
}

int atoi(char a[]) 
{
	int i = 0,f = 0, n = 0;
	if (a[0] == '-') 
	{ 
		f = 1;
	}
	n = 0;
	for (i = f; a[i] != '\0'; i++) 
	{
		n = n * 10 + a[i] - '0';
	}
	if (a[0] == '-')
	{
		n = -n;
	}
	return n;
}
