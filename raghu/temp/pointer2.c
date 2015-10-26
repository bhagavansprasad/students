#include <stdio.h>
main()
{
	int a=0x12131415;
	char *cp;
	char *p;
	int i, t;

	cp = (char *)&a;

	printf("-->%p :%x\n", cp+0, *(cp + 0));
	printf("-->%p :%x\n", cp+1, *(cp + 1));
	printf("-->%p :%x\n", cp+2, *(cp + 2));
	printf("-->%p :%x\n", cp+3, *(cp + 3));

	exit(1);

	
	for(i = 0; i < 4; i++)
	{
		if (i == 0 || i == 2)
		{
			t = *(p+i);
			*(p+i) = *(p+i+1);
			*(p+i+1) = t;
			printf("%x%x",*(p+i),*(p+i+1));
		}
	}
	printf("\n");
}
