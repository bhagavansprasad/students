#include <stdio.h>
#include <stdlib.h>
struct data
{
	int i;
}**q;
int main()
{
	struct data *p;
	p = malloc(sizeof(struct data));
	q = &p;
	printf("size of p : %p %d\n", p, sizeof(p));
	q->p->i = 20;
	return 0;
}
