#include <stdio.h>
void main()
{
	int i, n=4,temp=0;
    int x[10]={10,20,30,40};
    printf("|%d| |%d|\n",x[2],x[3]);
	temp=x[2];
	x[2]=x[3];
	x[3]=temp;
    printf("|%d| |%d|\n",x[2],x[3]);
	printf("\nResultant Array...\n");
    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %d\n", i, x[i]);
    }

}

