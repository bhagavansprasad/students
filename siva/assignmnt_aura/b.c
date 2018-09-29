#define MY_NUMBER 5

int *factorial(int n)
{
int fact = 0,i;

for (i = 0; i <= n; i++)
{
	fact = fact * i;
}

return &fact;
}

main()
{
	int *fact ;

fact = factorial(MY_NUMBER);

printf("factorial value %d\r\n", *fact);
}
