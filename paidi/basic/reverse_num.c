#include<stdio.h>
int main()
{
    int num,r,reverse=0;
    num = 1234;
   // printf("Enter any number: ");
    //scanf("%d",&num);

    for(;num!=0;num=num/10)
	{
         r=num%10;
         reverse=reverse*10+r;
    }

    printf("Reversed of number: %d\n",reverse);
    return 0;
}

