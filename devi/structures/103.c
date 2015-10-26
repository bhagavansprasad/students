#include <stdio.h>
struct std
{
	int a;
	int b;
};

int main()
{
	struct std s1 = {1,2}; 
	int i;
	char *ptr = &s1;
	struct std *p;
	p = &s1;
	printf("\nsize of sstructure is %d", sizeof(s1));
	printf("\nptr->a =%d",p->a);
	printf("\nptr->a =%u",&(p->a));
	printf("\nptr->b =%d",p->b);
	printf("\nptr->b =%u",&(p->b));
	printf("\nptr->a =%d",(*p).a);
	//printf("\nptr->a =%u",&(p->a));
	for(i = 0; i< sizeof(s1);i++)
	{
		printf("\naddress--> %u", ptr);
		ptr++;
	}
}
