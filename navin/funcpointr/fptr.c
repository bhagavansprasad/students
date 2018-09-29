#include <stdio.h>
//#include <stdlib.h>
typedef int FUNC(int , int);

FUNC sum, subtract, mul, div;
FUNC *p[4] = { sum, subtract, mul, div };

int main(void)
{
    int res;
    
    int i = 2, j = 3;
	int op;

	for(op =0;op<=3;op++)  // 2: mul
	{
		res = p[op](i,j);   // = 6  
		printf("%d \n",res);
	}

}

// maybe even in another file
int sum(int a, int b) { return a+b; }
int subtract(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int div(int a, int b) { return a/b; }
