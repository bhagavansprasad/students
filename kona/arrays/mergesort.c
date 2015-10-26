#include <stdio.h>
main()
{
	int a[5]={5,8,9,28,34};
	int b[5]={4,7,10,13,45};
	int c[10];
	int i,j,k,t;
	for(i=0;i<=3;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
		for(i=j=k=0;i<=9; )
		{
			if(a[j++]<=b[k++])
				c[i++]=a[j++];
			else
				c[i++]=b[k++];
			if(j==5 ||k==5)
				break;
		}
		for( ;j<=4; )
			c[i++]=a[j++];
		for( ;k<=4 ;)
			c[i++]=b[k++];
	}
	for(i=0;i<10;i++)
		printf("%d\n",c[i]);
}
