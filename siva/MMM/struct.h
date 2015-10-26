#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
void *fb;
int flag;
struct node *next;
}node;
node *head=NULL;

/* function Prototypes*/

void init_free_pool(void);
int add_to_free_pool(char *,int);
void *amalloc(int size);
void afree(char *);
