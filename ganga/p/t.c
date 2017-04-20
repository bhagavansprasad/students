#include "stdio.h"

struct t1
{
	int a;
	char b;
	int c;
};

struct t2
{
	char a;
	int b;
};


#define UL unsigned long

main()
{
	struct t1 s1;
	struct t2 s2;
	printf("int size :%ld\n", sizeof(int));
	printf("shi size :%ld\n", sizeof(short));
	printf("-->i c i\n");
	printf("	expsz :%d, act :%d, pad :%d\n", (int)9, (int)sizeof(struct t1), (int)sizeof(struct t1)-9);
	printf("	i:%lu, c:%lu, i:%lu\n", (UL)&s1.a, (UL)&s1.b, (UL)&s1.c);
	printf("	i:%lu\n", (UL)&s1.a);
	printf("	c:%lu\n", (UL)&s1.b - (UL)&s1.a);
	printf("	i:%lu\n", (UL)&s1.c - (UL)&s1.b);

	printf("-->c i\n");
	printf("	expsz :%d, act :%d, pad :%d\n", (int)5, (int)sizeof(struct t2), (int)sizeof(struct t2)-5);
	printf("	c:%lu, i:%lu\n", (UL)&s1.a, (UL)&s1.b);
	printf("	c:%lu\n", (UL)&s2.a);
	printf("	i:%lu\n", (UL)&s2.b - (UL)&s2.a);

}
