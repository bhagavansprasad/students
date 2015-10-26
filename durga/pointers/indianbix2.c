#include <stdio.h>
int i;
void fun (void *);
main()
{
	void *ptr;
	 ptr = &i;
	 fun(ptr);
}

void fun (void *q)
{
 int **p;
  p = (int** )&q;
  
  printf("%d\n", **p);
}
