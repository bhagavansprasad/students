#include<stdio.h>

int n = 5;

int db_delete_element(int *p,int index)
{
	int i;
	for(i = index-1;i < n;i++)
	{
		p[i] = p[i+1];
	}
	
	for(i = 0;i < n-1;i++)
	{
		printf("%d\n",p[i]);
	}
	return 0;	
}


main()
{
	int a[] = {10,20,30,40,50};
	int index = 4;
	
	db_delete_element(a,index);
}
	
