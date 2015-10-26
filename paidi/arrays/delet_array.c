#include<stdio.h>
int main()
{
	int a[5]={1,4,2,3,5},i,pos=4;

	for(i=0;i<5;i++)
	printf("%d\t",a[i]);
	printf("\n");

	i=0;
	while(i!=pos-1)
	i++;
	while(i<5)
	{
	a[i]=a[i+1];
	i++;
	}
	a[i]--;
	for(i=0;i<5;i++)
	printf("%d\t",a[i]);
	printf("\n");
}

