#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct node
{
char *fb;
int flag;
struct node *next;
}node;
node *head[27]={NULL};

/* function Prototypes*/
void * thread_function1(void *arg);
void * thread_function2(void *arg);
void * thread_function3(void *arg);
int add_to_free_pool(char *,int);
void display();
char gen_hashkey(int);
void init_free_pool(void);
void *amalloc(int);
void afree(char *);

