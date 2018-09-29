#include "stdio.h"
int showspec(int i,int s , int d);
void showbit(int i);
void main()
{
int
	i=106,j;
	int s=1, d=3;
//	printf("%d\n",i);
	printf("the bit value of i is --->%d\n",i);
	showbit(i);
	
	j=showspec(i,s,d);
	printf("the bit value of j is --->%d\n",j);
	showbit(j);

}


int showspec(int i,int s , int d)
{
int j;
int mask, k=0,sum=0;
	for( j = d ; j >= s ; j--)

	{
		mask=1<<j;
		k = i & mask;
		sum=sum+k;
	}
	return(sum);
}

void showbit(int i)
{
	int j=2;
	int mask,k;
	
	for( j = 31 ; j >= 0 ; j-- )
	{
		mask=1<<j;

		k = i & mask;
		
		if(k==0)
		{
			printf("0");
		}
		else
		{	
			printf("1");
		}
	}
	printf("\n");
}
