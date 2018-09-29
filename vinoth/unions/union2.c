#include <stdio.h>

union data
{
	int i;
	char b[4];
};

int main()
{
	union data u;
	u.i = 300;
	printf("%d\t",u.b[0]);
	printf("%d\t",u.b[1]);
	printf("%d\t",u.b[2]);
	printf("%d\n",u.b[3]);

}
