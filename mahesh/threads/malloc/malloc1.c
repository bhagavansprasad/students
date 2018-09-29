#include <stdio.h>
#include <string.h>
main()
{
	char *p;
	p=malloc(100);
	strcpy(p,"bangalore");
	printf("---->p : %u\n",p);
	printf("---->p-1 : %u\n",*(p-1));
	printf("---->p-2 : %u\n",*(p-2));
	printf("---->p-3 : %u\n",*(p-3));
	printf("---->p-4 : %u\n",*(p-4));
	printf("---->p : %u\n",*(p));
	printf("---->p : %s\n",p);
	*(p-1)=1;
	//*(p-2)=2;
//	*(p-3)=2;
//	*(p-4)=2;
	free(p);
	printf("---->p : %s\n",p);
}
