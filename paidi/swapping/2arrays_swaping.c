#include <stdio.h>
void my_function(int *,int *);

void my_function(int *ptr1, int *ptr2 )
{
	printf("|%d| |%d|\n",*ptr1,*ptr2);
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
	printf("|%d| |%d|\n",*ptr1,*ptr2);
}

void main()
{
    int x[10]={10,20,30,40};
	int i, n=4;
    my_function(x+2,x+3);
    printf("\nResultant Array...\n");
    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %d\n", i, x[i]);
    }
}

