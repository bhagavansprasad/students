#include <stdio.h>
main()
{
	int i,j,n=5,t;
	int a[5]={5,4,1,3,2};
	printf("numbers in array:\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	for(i=1;i<n;i++)
	{
	printf("\n\ni value is %d\n",i);
		t=a[i];
		for(j=i-1;j>=0;j--)
		{
		printf("j value is %d\n",j);
			if(t<a[j])
			{
				a[j+1]=a[j];
				printf("a[%d]=%d\n",j+1,a[j+1]);
			}
			else
			break;
		}
	//	printf("\n");
		a[j+1]=t;
		printf("a[%d]=%d",j+1,a[j+1]);
	}
	for(i=0;i<n;i++)
		printf("\n%d\t",a[i]);
}
