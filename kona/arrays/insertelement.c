#include <stdio.h>

int main()
{
    int array[10]={1,2,3}, position=3, i, n=10, value=20; 
    for (i = n - 1; i >= position - 1; i--)    
		array[i+1] = array[i]; 
    array[position-1] = value;
    
    printf("Resultant array is\n");
    
    for (i = 0; i <= n; i++)    
		printf("%d\n", array[i]);    
    
    return 0;
	}
