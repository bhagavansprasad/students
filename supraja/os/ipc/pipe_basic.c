#include <stdio.h>
int main()
{
	int p[2];
	pipe(p);
	printf("p[0]is %dp[1]is%d\n",p[0],p[1]);
}
