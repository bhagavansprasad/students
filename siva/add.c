
#include<stdio.h>
main()
{
int n;
int sum=0;
printf("enter the number\n");
scanf("%d",&n);
sum=sum+n%10;
n=n/10;
sum=sum+n%10;
n=n/10;
sum=sum+n%10;
n=n/10;
printf("sum of 3 digits number is %d\n",sum);
}









