#include <stdio.h>
#include "mem_req.h"
struct node
{
	int flag;
	void *p;
	struct node *N;
};

main()
{
	int size=0;
	int size_header;
	int i;

	//printf("size---->%d\n",sizeof(mem_req));
	//printf("size---->%d\n",sizeof(mem_req[0]));
	
	printf("size---->%d\n",sizeof(struct node));
	
	for(i=0;i<9;i++)
	{
		size = size+(mem_req[i][0]*mem_req[i][1])+sizeof(struct	node)+sizeof(size_header);
	}
	printf("size---->%d\n",size);
}
