#include<stdio.h>
union union_tag
{
    int a;
    char *name;
};
int main()
{
    union union_tag x;
    x.a = 26; 
    x.name = "Bob";
    printf("%s",x.a);
    return 0;
}


