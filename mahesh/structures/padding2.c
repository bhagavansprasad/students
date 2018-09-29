#include <stdio.h>
#include <string.h>

/*  Below structure1 and structure2 are same. 
    They differ only in member's allignment */

#pragma pack(1)
struct structure1 
{
       int id1;
       int id2;
       char name;
       char c;
       float percentage;
};

struct structure2 
{
       int id1;
       char name;
       int id2;
       char c;
       float percentage;                      
};

int main() 
{
    struct structure1 a;
    struct structure2 b;

    printf("size of structure1 in bytes : %d\n",
                   sizeof(a));
    printf ( "\n   Address of id1        = %u", &a.id1 );
    printf ( "\n   Address of id2        = %u", &a.id2 );
    printf ( "\n   Address of name       = %u", &a.name );
    printf ( "\n   Address of c          = %u", &a.c );
    printf ( "\n   Address of percentage = %u", 
                   &a.percentage );

    printf("   \n\nsize of structure2 in bytes : %d\n", 
                   sizeof(b));
    printf ( "\n   Address of id1        = %u", &b.id1 );
    printf ( "\n   Address of name       = %u", &b.name );
    printf ( "\n   Address of id2        = %u", &b.id2 );
    printf ( "\n   Address of c          = %u", &b.c );
    printf ( "\n   Address of percentage = %u", 
                   &b.percentage );
    getchar();
    return 0;
}
