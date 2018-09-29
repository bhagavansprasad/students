#include <stdio.h>
main()
{
	int a=-1,b=1,c=0,n=10,i;
	for(i=0;i<n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	printf(" %d\t",c);
	}
	printf("\n");
}




/* sum of fibonacci*/
/*#include<stdio.h>
int main()
{
    int k,r;
    long int i=0,j=1,f;
    long int sum = 1;

    printf("Enter the number range: ");
    scanf("%d",&r);

    for(k=2;k<r;k++)
	{
         f=i+j;
         i=j;
         j=f;
         sum = sum + j;
    }

    printf("Sum of Fibonacci series is: %ld",sum);
  
    return 0;
}
*/
/*Alogrithm:

What is Fibonacci series?

Logic of Fibonacci series

Definition of Fibonacci numbers:

We assume first two Fibonacci are 0 and 1
A series of numbers in which each sequent number is sum of its two previous numbers is known as Fibonacci series and each numbers are called Fibonacci numbers. So Fibonacci numbers is

Algorithm for Fibonacci series 

Fn = Fn-2 + Fn-1

Example of Fibonacci series:

0 , 1 ,1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55  ...

5 is Fibonacci number since sum of its two previous number i.e. 2 and 3 is 5
8 is Fibonacci number since sum of its two previous number i.e. 3 and 5 is 8 and
so on.*/
