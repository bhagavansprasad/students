#include <stdio.h>
main()
{
	int a[5]={2,6,8,4,9};
	int i,j,temp;
	for(i=0;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[j] = a[i];
				a[i] = a[temp];
			}
		}
	printf("first highest------> %d\n",a[4]);
	printf("second highest------> %d\n",a[3]);
	}
}
