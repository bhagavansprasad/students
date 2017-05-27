#include <stdio.h>
int main()
{
	int first=-1,second=1,third,i,n=5,sum=0;
	
	for (i=1;i<=n;i++)
	{
		third=first+second;
		printf("%d\n",third);
		sum=sum+third;
				first=second;
		second=third;
		}
           printf(" sum= %d\n",sum);
	return 0;
}


