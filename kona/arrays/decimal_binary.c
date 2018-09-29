#include <stdio.h>
main()
{
	int num,arr[15],i,j;
	printf("enter a decimal number :");
	scanf("%d",&num);
	i=0;
	while(num>0)
	{
		arr[i]=num%2;
		num=num/2;
		printf("%d,%d\t",arr[i],num);
		i++;
		}
	printf("\n");
			for(j=i-1;j>=0;j--)
		printf("%d\t",arr[j]);
}
