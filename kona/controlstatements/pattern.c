#include<stdio.h>

int main()
{
	int i,j,p;
	for(i=1;i<=4;i++)
	{
		if(i==2)
		{
			for(p=1;p<=2;p++)
			printf("%d",p);
			printf("\n");
		}
		for(j=1;j<=i;j++)
			printf("%d",j);
		for(j=i-1;j>=1;j--)
			printf("%d",j); 
		printf("\n");
	}
	return 0;
}  
