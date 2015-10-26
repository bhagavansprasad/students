#include <stdio.h>
main()
{
	int a  = 10;
	int *p;
	*p = &a; // warning
	printf("%p\\n\n", *p);
	printf("%p\\n\n", &a);
	printf("%d\n\n", a);
	*p=20;
	printf("%d\n", *p);
}
/*#include <stdio.h>
main()
{
	int a  = 10;
	int *p;
	p = &a;
	printf("%p\\n\n", *p);
	printf("%p\\n\n", &a);
	*p=20;
	printf("%d\n", *p);
}
#include <stdio.h>
main()
{
	int a  = 10;
	int *p = &a;
	printf("%p\\n\n", *p);
	printf("%p\\n\n", &a);
	*p=20;
	printf("%d\n", *p);
}*/
