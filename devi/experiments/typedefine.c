#include <stdio.h>
#define MAX 100
typedef int c; 
int main()
{
	typedef int c;
	{
	typedef char c;
	printf("%c", c);
	}
	printf("%d",c);
	return 0;
}
