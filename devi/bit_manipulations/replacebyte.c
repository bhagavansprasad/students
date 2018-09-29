#include <stdio.h>
struct replace
{
	unsigned int x:16;
	unsigned int c:8;
};
main()
{
	struct replace r;
	r.x=257;
	r.c=1;
	int i,d;
	r.c = r.c<<8;
	//r.x = r.x>>8;
	for(i=8;i<(8+8);i++)
	 = r.x & (0<<i);
	d<<8;
	r.x = r.x^d;
	printf("x=%d\tc=%d\n",r.x,r.c);
}
