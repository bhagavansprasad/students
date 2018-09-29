#include <stdio.h>
main()
{
	int a[5]={1,2,3,4,5},c,d,b[5],n=5;
	for(c=n-1,d=0;c>=0;c--,d++)
	b[d]=a[c];
	for(c=0;c<n;c++)
	a[c]=b[c];
	for(c=0;c<n;c++)
	printf("%d\n",a[c]);
}
