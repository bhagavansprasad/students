#include <stdio.h>
int main()
{	
	int a[5]={1,2,3,4,5};
	int *p = (int *)&a;
	printf("%p %p %p %p %p\n%d %d %d %d\n",p,++p, p++, ++p, (++p),*++p, *p++, ++*p, *(++p));
	return 0;
}
