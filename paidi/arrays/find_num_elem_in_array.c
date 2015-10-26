#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int array[] = {15, 50, 34, 20, 10, 79, 100};
    int n; 
    n = sizeof(array);
    printf("num.of elements in array-->=%d\n", sizeof(array)/sizeof(int));

/*	int n=0,size=0,i;
	size = sizeof(array)/sizeof(0);
	for(i=1;i<=size;i++)
	{
	  printf("no.of array elents-->=%d\n",i);
	  n++;
	}
	  printf("for loop out side-->=%d\n",n);
*/

}
