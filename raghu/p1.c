#include <stdio.h>
#include <stdlib.h>
main()
{
	int x,y,z;
	x=y=z=1;
	z=++x||++y&&++z;
	/*int i=4,j=-1,k=0,w,x,y,z;
	w=i||j||k;
	x=i&&j&&k;
	y=i||j&&k;
	z=i&&j||k;*/
	printf("%d%d%d\n",x,y,z);
}
