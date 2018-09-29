#include<stdio.h>
union union_tag
{
    union 
    {
       int i;
       char *nickname;
    }b;
    int a;
    char * name;
};           
int main()
{
     int a = 10;
     union union_tag x={12};
     union union_tag *b = (union union_tag*)malloc(sizeof(union union_tag));
     b = &x;
     b->b.i = 20;
     printf("%d",x.b.nickname);
     return 0;
}

