#include<stdio.h>
int main()
{
	int n,i,data=2,flag=1,num=0;
	printf("enter num ");
	scanf("%d",&n);
	while(num<n)
	{
		for(i=2;i<data-1;i++)
		{
			if(data%i==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("%d",data);
			num++;
		}
		data++;
		flag=1;
		}
		}

	

