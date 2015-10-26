#include "stdio.h"
int showspec(int i,int pos);
void showbit(int i);
void main()
{
int
	i=42,j;
	int pos=2;
//	printf("%d\n",i);
	printf("the bit value of i is --->%d\n",i);
	showbit(i);
	
	j=showspec(i,pos);
	printf("the bit value of j is --->%d\n",j);
	showbit(j);

}


int showspec(int i,int pos)
{

int mask, k=0,sum=0;

		mask=i>>pos;
		//k = i & mask;
		
	printf("\n");
	showbit(mask);
	return(mask);
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
