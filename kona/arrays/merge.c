#include <stdio.h>
main()
{
	int a[5]={5,8,9,28,34};
	int b[7]={4,22,25,30,33,40,42};
	int c[12];
	int n1=5,n2=7,i;
	merge(a,b,c,n1,n2);
	for(i=0;i<n1+n2;i++)
	printf("%d\t",c[i]);
}
void merge(int a[],int b[],int c[],int n1,int n2)
{
	int i=0,j=0,k=0;
	while((i<=n1-1) && (j<=n2-1))
	{
		if(a[i]<b[j])
		c[k++]=a[i++];
		else
		c[k++]=b[j++];	
	}
	while(i<=n1-1)
	c[k++]=a[i++];
	while(j<=n2-1)
	c[k++]=b[j++];
}
