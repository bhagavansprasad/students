#include<stdio.h>
int main()
{
    struct Root
    {
       int x;
       struct Leaf
       {
            char s;
            struct Root *r;
       };
       struct Leaf *l;
    };
    return 0;
}

