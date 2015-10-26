#include <stdio.h>
int main()
{
	int arr[]={1,2,3,2,3,10,10,18,18,20,20};
	int i,j,size=0,k;
	size = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]==arr[j])
			{
				for(k=j;k<size;k++)
				{
					arr[k]=arr[k+1];
				}
				size--;
				j--;
			}
		}
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
/*
#include <stdio.h>
void my_function(int * ,int );
main()
{
int arr[]={1,2,3,2,3,10,11,8,7,1,1,3,4,5,4,3,2,3,};
int size=0;
size = sizeof(arr)/sizeof(arr[0]);
my_function(arr,size);
}
void my_function(int *arry,int size)
{
int i,j,k;
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(arry[i]==arry[j])
{
for(k=j;k<size;k++)
{
arry[k]=arry[k+1];
}
size--;
j--;
}

		}
		printf("%d\t",arry[i]);
	}
		printf("\n");
}
*/

