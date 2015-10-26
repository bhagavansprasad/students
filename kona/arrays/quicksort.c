#include <stdio.h>
main()
{
	int i;
	int a[10]={11,2,9,13,57,25,17,1,90,3};
	quicksort(a,0,9);
	for(i=0;i<10;i++)
		printf("%d\t",a[i]);
}
void quicksort(int a[],int lower,int upper )
{
	int i;
	if(upper>lower)
	{
		i=split(a,lower,upper);
		quicksort(a,lower,i-1);
		quicksort(a,i+1,upper);
	}
}
int split(int a[],int lower,int upper)
{
	int i;
	int p,q,t;
	p=lower+1;
	q=upper;
	i=a[lower];
	while(q>=p)
	{
		while(a[p]<i)
			p++;
		while(a[q]>i)
			q--;
		if(q>p)
		{
			t=a[p];
			a[p]=a[q];
			a[q]=t;
		}
	}
	t=a[lower];
	a[lower]=a[q];
	a[q]=t;
	return q;
}
