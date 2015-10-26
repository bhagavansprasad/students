#include<stdio.h> 
#include "string.h"
int main()
{
    enum sub{chemistry, maths, physics};
    struct result
    {
        char name[30];
        enum sub sc;
    };
    struct result my_res;
    strcpy (my_res.name,"C programming");
    my_res.sc=physics;
    printf("Name: %s\n",my_res.name);
    printf("Pass in subject: %d\n",my_res.sc);
    return 0;
}


