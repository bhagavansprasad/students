#include<stdio.h>

int main()
{
    char *p;
    p="%d\n";
    p++;
    p++;
    printf(p-2, 23);
    return 0;
}
