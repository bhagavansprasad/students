#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"string.h"

#define ROW 7
#define COLOUMN 2

char arr[] = "yvvr";

int total_buffer[ROW][COLOUMN]={
    {16,20},
    {32,20},
    {64,10},
    {128,10},
    {256,10},
    {512,10},
    {1024,2}
};

typedef struct node
{
    void *bptr;
    void *tptr;
    int  is_free;
    int size;
    int pid;
    int time;
    node_t *next;
}node_t;

node_t *h[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};

int build_key(int size)
{
    int val,ret;
    val = size/16;
    ret = val%16;
    if(ret>val)
	return val;

    return --val;
}

void * amalloc(int buf_size)
{
    node_t *temp;
    int key = build_key(buf_size);

    for(temp = h[key]; temp != NULL; temp=temp->next)
    {
	if(temp->is_free == 1)
	{
	    temp->is_free = 0;
	    temp->time = time(NULL);

	    return temp->bptr;
	}
    }
    printf("there are no  buffer's with this size  to allocate\r\n");
    return 0;
}

void *afree(node_t *ptr)
{   
    node_t *temp = ptr-1;
    int key = build_key(temp->size);

    key=build_key(temp->size);

    for(temp=h[key]; temp != NULL; temp = temp->next)
    {
	if(temp->bptr == ptr)
	{
	    if(temp->is_free !=1)
		temp->is_free = 1;
	    else
		printf("this buffer as already free \r\n");
	    return (temp->bptr);
	}
    }

    printf("the pointer is not valid\r\n");

    return 0;
}

void init_free_buffer(node_t *temp, int nbuff_size)
{   
    temp->bptr = (void *)(temp + 1);
    temp->tptr = (char *)((temp->bptr)+nbuff_size);
    temp->is_free = 1;
    temp->size = nbuff_size;
    temp->pid = 0;
    temp->time = 0;
    temp->next = NULL;
    temp->tptr = arr;
}

int add_to_freelist(node_t *temp, int size)
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

    for(i=0; i < ROW; i++)
    {
	for(j=total_buffer[i][1]; j>0; j--)
	{
	    init_free_buffer((node_t *)buff ,total_buffer[i][0]);
	    add_to_freelist((node_t *)buff, total_buffer[i][0]);
	    buff = buff + sizeof(node_t)+total_buffer[i][0];
	}
    }

    return 0;
}

int cal_buffer_size(void)
{
    int i,buffer_size = 0;
    for(i=0; i<ROW; i++)
	buffer_size =(total_buffer[i][0] + sizeof(node_t) + 5)*total_buffer[i][1]+buffer_size;
    printf("buffer_size:%d\r\n",buffer_size);
    return buffer_size;
}

void display(int buf_size)
{
    node_t *temp;
    int j ;
    int key = build_key(buf_size);

    for(temp = h[key],j = 0; temp != NULL; temp=temp->next)
    {
	printf("-->%3d:%-7p - %-7p - %-7p -%-2d - %-2d - %s\r\n",j++, temp, temp->bptr,temp->tptr,
	    temp->is_free,temp->time,temp->tptr);
    }
    printf("\r\n");
}


int main()
{         
    //int *p1,*p2 = NULL,*p3;
    int buff_size;
    void *buffer;
    buff_size=cal_buffer_size();
    buffer = malloc(buff_size);
    init_mmm(buffer);
    display(16);
    display(32);
    display(64);
    display(128);
    display(256);
    display(512);
    display(1024);
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
    return 0;
}





