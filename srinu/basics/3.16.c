#include"stdio.h" 
int main()
{
	int i,j,k,n=5;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			printf(" ");
		for(k=65;k<65+(2*j-1);k++)
			printf("%c",k);
	}
	for(j=1;j<=i;j++)
	{
		printf(" ");
		for(k=65;k<=68-(2*i-1);k++)
			printf("%c",k);
	}
	printf("\n");
}
