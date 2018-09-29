#include<stdio.h>

int n = 5;

int db_insert_element(int *p,int value)
{
	int i,j;
	
	for(i = 0;i < n;i++)
	{
		if(value > p[i])
		{
			p[n] = value;
		}
		else if(p[i] > value)
		{
			for(j = n -1;j >= i;j--)
			{
				p[j + 1] = p[j];		
			}
			p[i] = value;
			break;
		}
	}
	for(i = 0;i <= n;i++)
	{
		printf("%d\n",p[i]);
	}
	return 0;
}

main()
{
	int a[] = {10,20,30,40,50};
	int value = 11;

	db_insert_element(a,value);
}
