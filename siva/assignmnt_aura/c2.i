# 1 "c.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "c.c"



int factorial(int n)
{
 int fact = 0,i;


 printf("In function n value :%d\r\n", n);


 for (i = 0; i <= n; i++)
{

 printf("In loop fact and i values :%d - %d\r\n", fact, i);

 fact = fact * i;
 }


 printf("Before returning from function fact value :%d\r\n", fact);

 return fact;
}

main()
{
 int fact = 0;


printf("Before calling function my_number :%d\r\n", 5);

fact = factorial(5);

 printf("factorial value %d\r\n", fact);
}
