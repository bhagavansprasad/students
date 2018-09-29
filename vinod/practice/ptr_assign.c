#include <stdio.h>
int main()
{
	char *cptr = 0;
	int *iptr = 0;
	void *vptr = 0;
	cptr++;
	iptr++;
	vptr++;
	vptr++;
	printf("cptr:%p, iptr :%p, vptr :%p\n", cptr,iptr,vptr);
	return 0;
}
