#include<stdio.h>
int n = 5;

int db_insert_element(int *p,int value,int index)
{	int i;
	for(i = n-1;i >= index - 1 ;i--)
	{
		p[i+1] = p[i];
		
	}
	p[index-1] = value;
	for(i = 0;i <= n;i++)
	{
		printf("%d\n",p[i]);
	}
	return 0;
}
int main()
{
	int a[]= {10,20,30,40,50};
	int value = 60,index = 4;
	
	db_insert_element(a,value,index);

	return 0;
	
}
