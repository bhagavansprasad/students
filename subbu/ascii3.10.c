#include<stdio.h>
main()
{
	char a='A',n='E',d,k='E';
	for(a='A';a<=n;a++)
	{
		for(d='A';d<=k;d++)
		{
			printf("%c",d);
		}
		printf("\n");
		k--;
	}
}
