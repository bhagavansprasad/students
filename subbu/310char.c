#include<stdio.h>
main()
{
	char x=65,n=5,k=69,z;
	for(x='A';x<('A'+n);x++)
	{
		for(z='A';z<=k;z++)
		{
			printf("%c",z);
		}
		printf("\n");
		k--;
	}
}
