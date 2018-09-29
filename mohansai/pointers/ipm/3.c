#include "stdio.h"
#include "stdlib.h"
typedef struct node_t
{
	int  x ;
	char y ;
	short int z;
}node;


typedef struct ptr_t
{
	int  x ;
	char y ;
	short int z;
}ptr;

main()
{
	node *str = NULL;
	ptr  *str1 = NULL;
	
	str = malloc(sizeof(node));

		str->x = 10;
		str->y = 'A';
		str->z = 20;

	printf("ptr->x --> %d\n\r",str->x);
	printf("ptr->y --> %d\n\r",str->y);
	printf("ptr->z --> %d\n\r",str->z);


	//str1 = malloc(sizeof(ptr));
	str1=str;
	printf("str->x --> %d\n\r",str1->x);
	printf("str->y --> %d\n\r",str1->y);
	printf("str->z --> %d\n\r",str1->z);
}
