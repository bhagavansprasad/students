

/* Fibonacci Series using while loop */
// 0 1 1 2 3 5 8 13...
#include<stdio.h>
int main()
{
    int n,i,a,b,c;
    printf("Enter a number: ");
    scanf("%d",&n);
    i=1;
    a=0;
    b=1;
    while(i<=n)
    {
        printf("%d ",a);
        c = a + b;
        a = b;
        b = c;
        i++;
    }
 return 0;
}

/*
-----------------------------------------------------
*/
/* Fibonacci series using for loop 
// 0 1 1 2 3 5 8 13...

#include<stdio.h>
int main()
{
    int n,i,a,b,c;
    printf("Enter a number: ");
    scanf("%d",&n);
    a=0;
    b=1;
    for(i=1;i<=n;i++)
    {
        printf("%d ",a);
        c = a + b;
        a = b;
        b = c;
    }
 return 0;
}

*/
