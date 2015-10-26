#include<stdio.h>    
void main()
{
    int x = '\0';
    for( ; x ; x++)
    {
        if(x==5)
            break;
        else
            printf("%d",x);
    }
    printf("%d",x);
}


