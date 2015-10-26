#include "stdio.h"
#include "string.h"
void main()
{
    typedef union 
    {
        int     i;
        char    str[10];
    } 
    Un; 
    Un   x, y = { 100 };
    x.i = 50;
    strcpy (x.str, "Union");
    printf ("%d ,%s ", x.i, x.str);
    printf ("%d, %s\n", y.i, y.str);
}

