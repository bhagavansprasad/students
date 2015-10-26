#include<stdio.h>
main()
{
	int k,m,i,k1,k2;
	char  ch1=65,ch2=66,ch3=67,n=65,ch,d,j,m1;
	for(i=1;i<=3;i++)
	{
		for(ch=65;ch<=67;ch++)
		{
			printf("%c",ch);
		}
		for(k=n;k>n;k--)
		{
			printf(" ");
		}
		for(m=n;m>n;m--)
		{
			printf(" ");
		}
		for(d=n;d>=65;d--)
		{
			printf("%c",d);
		}
		for(i=1;i<=3;i++)
		{
			for(j=65;j<=n;j++)
			{
				printf("%c",j);
			}
			for(k1=2;k1>=n;k1--)
			{
				printf(" ");
			}
			for(k2=2;k2>=n;k2--)
			{
				printf(" ");
			}
			for(m1=n;m1>=65;m1--)
			{
				printf("%c",m1);
			}
			printf("\n");
		}
	}
}



