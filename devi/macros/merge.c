#include <stdio.h>
#define merge(a,b) b##a
//##(token pasting operator)prints concatenation of a and b
int main()
{
	//int a = 10 , b = 20;
	//merge(a,b);
	printf("%d",merge(10,20));
	return 0;
}
