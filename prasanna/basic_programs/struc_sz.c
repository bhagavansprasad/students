#include<stdio.h>

 struct  ABC{
    int a;
    float b;
    char c;
};
int main()
{
    struct ABC *ptr=NULL;
    ptr++;
    printf("Size of structure is: %d",*ptr);

    return 0;
}
