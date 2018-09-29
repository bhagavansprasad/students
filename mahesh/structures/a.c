#include <stdio.h>
struct node1
{
	int i1;
	int i2;
	char c1[3];
	char c2;
	short s;
	float f;
};
struct node1 n;
main()
{
	printf("%d\n",sizeof(struct node1));
	printf("i1 %u\n",&n.i1);
	printf("i2 %u\n",&n.i2);
//	printf("i1 %u\n",&n.i1);
	printf("c1 %u\n",&n.c1);
	printf("c2 %u\n",&n.c2);
	printf("s %u\n",&n.s);
	printf("f %u\n",&n.f);
}
