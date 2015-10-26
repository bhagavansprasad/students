#include <stdio.h>
extern int i;
extern int j;
void sum()
{
	int s;
	s=i+j;
	printf("%d\n", s);
}
