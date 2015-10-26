#include <stdio.h>
int main()
{
	int a[3][3][3];
	printf("%u %u %u\n",a,a+1,a+2);
	printf("%u %u %u\n",a[0],a[0]+1,a[1]);
	printf("%u %u %u\n",a[1][1],a[1][0]+1,a[0][1]);
	return 0;
}
