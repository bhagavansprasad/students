#include<stdio.h>
int a[]={5,7,9,2,3,10,20,30,78};
main()
{
	int flag;
	flag=linear_search(100);
	if(flag == 1)
	{
		printf("found\n");
	}
	else
	{
		printf("not found\n");
	}
}
linear_search(int n)
{
        int n1;  
	n1=sizeof(a)/4;
	printf("size of array%d\n",n1);
	int i;
	for(i=0;i<=n1;i++)
	{
		if(a[i]==n)
		{
			return 1;
		}
	}
	return 0;
}

