#include <stdio.h>
#define MAX 20
int main()
{
	int arr[MAX][MAX];
	int n =3,num,i,j;
	i = n-1;
	j = (n-1)/2;
	for(i=0;num<n*n;num++)
	{
		arr[i][j] = num;
		i++;
		j--;
		if(num%n == 0)
		{
			i-=2;
			j++;
		}
		else if(i == n)
			i=0;
		else if(j == -1)
			j = n-1;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%4d", arr[i][j]);
		printf("\n");
	}
	return 0;
}
