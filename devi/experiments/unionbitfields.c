#include <stdio.h>
union point
{
	int x;
	int y;
	int res;
};
int main()
{
	union point p;
	p.x=2;
	p.y=3;
	p.res=p.y;
	printf("%d\t%d\n",p.res,sizeof(p));
	return 0;
}
