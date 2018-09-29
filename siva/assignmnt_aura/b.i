# 1 "b.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "b.c"


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

fact = factorial(5);

printf("factorial value %d\r\n", *fact);
}
