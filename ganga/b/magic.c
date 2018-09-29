#include<stdio.h>
# define a 5
main()
{
	int d,f,n,b=1,c[a][a]={0},i=0,j=0;
	n=a*a;
	printf("%d\n",n);
	j=(a-1)/2;
	while(b<=n)
	{
		c[i][j]=b;
		d=i;
		f=j;
		i--;
		j++;
		if(i<0)
			i=a-1;
		if(j>(a-1))
			j=0;
		while(c[i][j]>0)
		{
			i=d++;
			j=f;
		}
		b++;
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
			printf("%5d",c[i][j]);
		}
		printf("\n");
	}


}
