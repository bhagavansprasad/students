#include <stdio.h>
struct dev
{
	int a;
	char b;
	short int c;
	int d;
	float e;
	char g;
};
int main()
{
	struct dev d1 = {1,'a',23,45,0,'b'};
	struct dev d2;
	int size = 16;
	d1.e = 67.89;
	printf("\nexpected size is %d size of dev is %d", size, sizeof(d1));
	printf("d1.a = %d\n", d1.a);
	printf("d1.b = %c\n", d1.b);
	printf("d1.c = %d\n", d1.c);
	printf("d1.d = %d\n", d1.d);
	printf("d1.e = %f\n", d1.e);
	printf("d1.g = %c\n", d1.g);
	d2 = d1;
	printf("d1.a = %d\n", d2.a);
	printf("d1.b = %c\n", d2.b);
	printf("d1.c = %d\n", d2.c);
	printf("d1.d = %d\n", d2.d);
	printf("d1.e = %f\n", d2.e);
	printf("d1.g = %c\n", d2.g);

}
