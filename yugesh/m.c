#include <stdio.h>
main()
{
	char a='A',n=5,l=68,x,k=69,p=68,i=4,s;
	for(a='A';a<('A'+n);a++)
	{
		for(x='A';x<=k;x++)
		{
			printf("%c",x);
		}
		for(s=i-5;s>0;s--)
		{
			printf(" ");
		}
		if(a>=67)
			l--;
		for(p=l;p>=65;p--)
		{
			printf("%c",p);
		}
		printf("\n");
		k--;
		i=i+2;
	}
}
