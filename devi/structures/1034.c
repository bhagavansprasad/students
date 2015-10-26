#include <stdio.h>
struct std
{
	int c;
	char a;
	int d;
	char b;
};

int main()
{
	struct std s1;
	int i;
	char *ptr = &s1;
	struct std *s = &s1;
	printf("\nsize of sstructure is %d", sizeof(s1));
	printf("\naddress of int c = %u", &(s->c));
	printf("\naddress of char a = %u", &(s->a));
	printf("\naddress of int c = %u", &(s->d));
	printf("\naddress of char b = %u", &(s->b));
	for(i = 0; i< sizeof(s1);i++)
	{
		printf("\naddress--> %u", ptr);
		ptr++;
	}
}
