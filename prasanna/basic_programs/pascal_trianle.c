#include<stdio.h>

main()
{
	int bin,p,q,r,x;

	bin=1;
	q=0;

	printf("Rows you want to input:\n");
	scanf("%d",&r);

	printf("Pascal's Triangle:\n");

	while(q<r)
	{
		for(p=30-3*q;p>0;--p)
			printf(" ");
		for(x=0;x<=q;++x)
		{
			if((x==0)||(q==0))
				bin=1;
			else
				bin=(bin*(q-x+1))/x;
			printf("%6d",bin);
		}
		printf("\n");
		++q;
	}
}
