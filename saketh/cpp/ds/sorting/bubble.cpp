#include<iostream>
#include<cstdlib>
using namespace std;
extern int data[10];

int bubble_sort(int n)
{
	int i = 0, j = i+1, a, b, temp=0;

	for(i=0;i<=n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(data[j]<=data[i])
			{
				temp=data[j];
				data[j]=data[i];
				data[i]=temp;
			}
		}
	}
	return 0;	
}
