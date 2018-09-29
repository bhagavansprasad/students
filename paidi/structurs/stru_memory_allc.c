#include <stdio.h>
#include <string.h>

struct student 
{
       int id1;
       int id2;
       char a;
       char b;
       float percentage;
};

int main() 
{
    int i;
    struct student record1 = {1, 2, 'A', 'B', 90.5};

    printf("size of structure in bytes : %d\n",sizeof(record1));

    printf("\nAddress of id1        = %u, %d", &record1.id1, record1.id1);
    printf("\nAddress of id2        = %u, %d", &record1.id2, record1.id2);
    printf("\nAddress of a          = %u, %c", &record1.a, record1.a);
    printf("\nAddress of b          = %u, %c", &record1.b, record1.b);
    printf("\nAddress of percentage = %u, %f\n",&record1.percentage, record1.percentage);

    return 0;
}
