#include "amalloc.h"
#include "list.h"

void *amalloc(int size)
{

	void *p;
	printf("Entered Amalloc :\n");
	p=malloc(size);
	append_node(size,p);
	printf("Returned Amalloc :\n");
	return p;
}
void afree(void *p)
{	
	printf("Enter Free :\n");
	free(p);
	delete_node(p);
	printf("Returned Free : \n");
	return;

}

