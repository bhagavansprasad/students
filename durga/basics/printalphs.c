#include<stdio.h>
main()
{
	int i,j,k,n=3;
	for(k=1;k<=n;k++)
	{
		for(i=65;i<=68-k;i++)
         printf("%c",i);
		for(j=1;j<=k-1;j++)
			printf(" ");
		if(k==1)
			i=i-1;
		if(k==3)
			printf(" ");
		for(j=i-1;j>=65;j--)
			printf("%c",j);
		printf("\n");
		}
	
	for(k=2;k>0;k--)
		{
			for(i=65;i<=68-k;i++)
				printf("%c",i);
				for(j=1;j<k;j++)
				printf(" ");
				if(k==1)
				i=i-1;
				for(j=i-1;j>=65;j--)
				printf("%c",j);
			printf("\n");
}
}
