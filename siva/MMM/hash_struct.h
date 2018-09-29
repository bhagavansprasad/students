#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
char *s;
struct node *next;
}node;
node *head[27]={NULL};

/* function Prototypes*/
int insert(char *);
int afree(char *);

