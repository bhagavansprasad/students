#include<stdio.h>
main()
{
	int i,m=0,a=20,c=0,b[8]={0};
	for(i=0;i<8;i++)
	{	
		m=1<<i;
		printf("%d\n", m);
		c=a&m;
		if(c==0)
			b[i]=0;
		else
			b[i]=1;
	}
	for(i=7;i>=0;i--)
		printf("%d",b[i]);
	printf("\n");
}

