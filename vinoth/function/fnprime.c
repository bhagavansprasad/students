#include<stdio.h>
main()
{
	int x=0, t=1, i,s=0, n=5;
	for (i=1; x<n; i++)
	{
		t=firstprimeno(i);
		if (t==1)
		{
			printf("%d\n", i);
			s = s+i;
			x++;
		}
	}
		printf("sum = %d\n",s);

}
int firstprimeno (int i)
{
	int f=0, j;
	for (j=2; j<i; j++)
	{
		if (i%j==0)
		{
			return 0;
			break;

		}
		
	}
	if(i==j)
		return 1;

}


