#include <stdio.h>
#include <stdlib.h>

//int cal(int);
main()
{
 char*p;
 char*a = malloc(10);
 printf("%u\n",a);
 p = realloc(a,0);
 printf("%u\n",p);
 char*c=calloc(5,50);
 int i=0;
 for(i=0;i<5;i++);
 {
 	printf("%u\n",c);
	c++;
 	
 }
}
/* cal(a);
 }
 int cal(int* size)
 {
 int p;
 p = relloc(size,0);
 printf("%d\n",p);
}*/
