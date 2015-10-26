#include <stdio.h>
int main()
{
	int n= 10, c= 0,count = 0, n = 5, sum=0,i=1,j=2; 
	
	for(i=2;;i++)
	{
	count = 0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				count++;
				break;
			}
		}
		if(count == 0)
		{
			sum = sum + i;
			c++;
			printf("prime %d\n",i);
		}
		if(c == num)
		break;
	}
	printf("sum = %d ",sum);

	return 0;
}
