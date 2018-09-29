#include<stdio.h>

/* int main()
{
	int num = 1;

	print(num);

	return 0;
}
int print(num)
{
	if(num<=100)
	{
		printf("%d ",num);
		print(num+1);
	}
}*/


int main()
{
	int i=0;
	numbers(i);
}
int numbers(i)
{
	if(i<100)
	{
		printf("%3d  ",i);
		numbers(i+1);	  
	}

}
