#include<stdio.h>
main()
{
	int i=32,j=65,k,l,m,n,o,p,q;
	k=i|35;
	l=~k;
	q=~(5);
	m=i&j;
	n=j^32;
	o=j<<2;
	p=i>>5;
	printf("k=%d l=%d m=%d\n",k,l,m);
	printf("n=%d o=%d p=%d q=%d q=%x \n",n,o,p,q,q);
}
