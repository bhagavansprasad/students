/* Prime Number using while loop */

#include<stdio.h>
int main()
{
    int a,i,f;
    printf("Enter a number: ");
    scanf("%d",&a);
    f=0;
    i=2;
    while(i <= a/2)
    {
        if(a%i == 0)
        {
            f=1;
            break;
        }
        i++;
    }
    if(f==0)
        printf("Prime Number\n");
    else
        printf("Not Prime Number\n");
 return 0;
}

/*-------------------------------------------------------*/

/* Prime number using for loop */
/*
#include<stdio.h>
int main()
{
    int a,i,f;
    printf("Enter a number: ");
    scanf("%d",&a);
    f=0;
    for(i=2;i <= a/2;i++)
    {
        if(a%i == 0)
        {
            f=1;
            break;
         }
    }
    if(f==0)
        printf("Prime Number")
    else
        printf("Not Prime Number");
 return 0;
}
*/
