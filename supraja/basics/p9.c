#include "stdio.h"
main()
{
	char ch1=65,ch2=66,ch3=67,ch,k,m,d,n=67,i=65,j,k1,m1,i1,k2;
	for(n=67;n>=65;n--,i++)
	{
		for(ch=65;ch<=n;ch++)
		{
			printf("%c",ch);
		}
		for(k=i;k>65;k--)
		{
			printf(" ");
		}
		for(k=i;k>65;k--)
		{
			printf(" ");
		}
		for(ch=n;ch>=65;ch--)
		{
			printf("%c",ch);
		}
		for(i1=65;i1<=67;i1++,i++)
		{
			for(j=65;j<=i1;j++)
			{
				printf("%c",j);
			}
			for(k1=2;k1>=i1;k1--)
			{
				printf(" ");
			}
			for(k1=2;k1>=i1;k1--)
			{
				printf(" ");
			}
			for(m1=i;m1>=65;m1--)
			{
				printf("%c",m1);
			}
			printf("\n");
		}
	}
}	

