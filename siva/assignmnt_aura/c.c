#define MY_NUMBER 5
//#define DEBUG

int factorial(int n)
{
	int fact = 0,i;

#ifdef DEBUG
	printf("In function n value :%d\r\n", n);
#endif

	for (i = 0; i <= n; i++)
{
#ifdef DEBUG
	printf("In loop fact and i values :%d - %d\r\n", fact, i);
#endif
	fact = fact * i;
	}

#ifdef DEBUG
	printf("Before returning from function fact value :%d\r\n", fact);
#endif
	return fact;
}

main()
{
	int fact = 0;

#ifdef DEBUG
printf("Before calling function my_number :%d\r\n", MY_NUMBER);
#endif
fact = factorial(MY_NUMBER);

	printf("factorial value %d\r\n", fact);
}
