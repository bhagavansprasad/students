#include <stdio.h>
main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9},i,j,temp;
	for(i=0,j=9;i<j;i++,j--)
	{
		temp = a[i];
		a[i] = a[j];
		printf("%d\n",a[i]);
		a[j] = temp;
		printf("%d\n",a[j]);
	}
	for(j=0;j<10;j++)
		printf("%d",a[j]);
	printf("\n");
}
