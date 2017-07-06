#include <stdio.h>
main()
{
	int n=11;
	char src[100]="aura net kadubeesnahalli";
	char dest[100];
	astcpy(dest,src);
	printf("\ndest :%s\n\n",dest);
	astncpy(dest,src,n);
	printf("\n nth dest :%s,%d\n\n",dest,n);
}
