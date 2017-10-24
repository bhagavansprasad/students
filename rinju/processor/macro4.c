#include<stdio.h>
#define N 5
main()
{
	int i,j,a=65,temp;
	{
		temp=a;
		for(j=0;j<N;j++)
		{
			if(i<=N/2 && j>N/2-i && j<N/2+i)
				printf(" ");
			else if(i>N/2 && j>N/2-(N-i)+1 && j< N/2+(N-i)-1)
				printf(" ");
			else 
				printf("%c",temp);

			if(j<N/2)
				temp++;
			else
				temp--;

		}
		printf("\n");
	}

}
