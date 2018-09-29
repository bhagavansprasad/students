//$ gcc main.c -E -o main.i
//$ gvim -d main.c main.i
#include<stdio.h>
#define  MAX 5

main()
{
	int i=0;
	for(i = 1; i<= MAX; i++)
	{ 

		printf("-->%d\n", i);
	}
}
