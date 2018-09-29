#include <stdio.h>
main()
{ 
	int i,j;
	
	int a[8]={2,2,2,2,2,1,2,2};
	for(i=0;i<8;i++)
	{
		for(j = i+1 ;j < 8;j++)
		{
			if(a[i] == a[j])
			{
				a[j]=0;
			}
		}
	}
	for(i = 0; i < 8; i++)
	{
		printf("%d\t ",a[i]);
	}
}
