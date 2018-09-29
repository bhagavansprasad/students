#include "stdlib.h"
void * S[100];
int top = 0;

void push(void *p)
{
    S[top] = p;
    top++;
}

void * pop()
{
    void * t =  NULL;

    if (top <= 0)
        return NULL;

    t = S[top-1];
    top--;
    return t;
}

int is_stack_empty()
{
    if (top)
        return 0;
    else
        return 1;
}

void init_stack()
{
    top = 0;
}
