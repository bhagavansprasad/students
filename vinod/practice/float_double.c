#include <stdio.h>
int main()
{
	float x=2.2;
	double y=x;
	printf("x:%f\ny:%e\n", x,y);
	if(x==y)
	printf("x:%f\ny:%e\n", x,y);
	return 0;
}
