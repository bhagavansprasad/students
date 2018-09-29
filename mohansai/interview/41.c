#include<stdio.h>
#define big(x,y) x>y?x:y
#define swap(m,n) temp=m; m=n; n=temp;
int main()
{
    int a=3,b=5,temp=0;
    if ((1+big(a,b)) > b)swap(a,b);
         printf("%d %d",a,b);
    return 0;    
}

