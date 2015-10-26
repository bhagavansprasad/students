#include<stdio.h>

int test(int i)
{
    return i;
}
int test(int i, int j)
{
    return i*j;
}

void main()
{
    printf("%d ",test(4, 5)); 
    printf("%d",test(5)); 
}

	

