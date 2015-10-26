#include"stdio.h"
#include"stdlib.h"

#define ROW 7
#define COLOUMN 2

int total_buffer[ROW][COLOUMN]={
    {16,20},
    {32,20},
    {64,10},
    {128,10},
    {256,10},
    {512,10},
    {1024,2}
};

struct node
{
    void *nptr;
    int  is_free;
    int size;
    struct node *next;
};

struct node *h[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};

void *amalloc(int buf_size)
{
    struct node *temp;
    int key;
	for(temp = h; temp != NULL; temp=temp->next)
	{
	    if(temp->size == buf_size)
	    {
		if(temp->is_free == 1)
		{
		    temp->is_free = 0;
		    return temp->nptr;
		}
	    }
	}

    printf("there are no  buffer's with this size  to allocate\r\n");
}

void *afree(void *ptr)
{   
    int i;
    struct node *temp;
	for(temp=h; temp != NULL; temp = temp->next)
	{
	    if(temp->nptr == ptr)
	    {
		if(temp->is_free !=1)
		    temp->is_free = 1;
		else
		    printf("this buffer as already free \r\n");
		return (temp->nptr);
	    }
	}
    printf("the pointer is not valid\r\n");
}

void init_free_buffer(struct node *temp, int nbuff_size)
{
    temp->nptr = (void *)(temp + 1);
    temp->is_free = 1;
    temp->size = nbuff_size;
    temp->next = NULL;
}

int build_key(int size)
{
int val;
val = size/16;
ret = val%16;
if(ret>val)

return --val;


}

int add_to_freelist(struct node *temp, int size)
{
    int key;
    key=build_key(size);
    temp -> next = h[key];
    h[key] = temp;
    return 0;
}

int init_mmm(void *buff)
{
    int i,j;
    void *ptr;

    for(i=0; i<ROW; i++)
    {
	for(j=total_buffer[i][1]; j>0; j--)
	{
	    init_free_buffer((struct node *)buff ,total_buffer[i][0]);
	    add_to_freelist((struct node *)buff, total_buffer[i][0]);
	    buff = buff + sizeof(struct node)+total_buffer[i][0];
	}
    }

    return 0;
}

int cal_buffer_size()
{
    int i,buffer_size = 0;

    for(i=0; i<ROW; i++)
	buffer_size =total_buffer[i][0]*total_buffer[i][1]+sizeof(struct node)*total_buffer[i][1]+buffer_size;

    return buffer_size;
}

void display(void)
{
    struct node *temp;
    int i,j ;
    for(i=0; i<ROW; i++)
    {
	for(temp = h[i],j=0; temp != NULL; temp = temp->next)
	{
	    printf("-->%3d:%-7x - %-7x - %-2d\r\n",j++, temp, temp->nptr, temp->is_free);
	}
	printf("\r\n");
    }
}

main()
{         
    int *p1,*p2 = NULL,*p3;
    int buff_size;
    void *buffer;
    buff_size=cal_buffer_size();
    buffer = malloc(buff_size);
    init_mmm(buffer);
    display();
#if 0
    afree(p2); 
    p1 = amalloc(100);
    p2 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    afree(p2); 
    afree(p2); 
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    p1 = amalloc(100);
    afree(p2); 
#endif
}



