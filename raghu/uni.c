#include <stdio.h>
union std
{
	int a=50;
	int b;
	char c;
	short int d;
}abc;

main()
{
	printf("%d",abc.a);
	printf("%d",abc.b);
	printf("%c",abc.c);
	printf("%s",abc.d);

}
