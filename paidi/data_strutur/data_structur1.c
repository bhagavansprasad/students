#include<stdio.h>
#include<string.h>
main()
{
 
struct vari
{
 char a;
 char b;
 int c;
 int d
};
struct vari f1;
printf("size of%d\n",sizeof(f1));
printf("addre==%u\n",&f1.a);
printf("addre==%u\n",&f1.b);
printf("addre==%u\n",&f1.c);
printf("addre==%u\n",&f1.d);

struct var
{
 char a;
 int b;
 char c;
 int d;
};
struct var f;
printf("size of%d\n",sizeof(f));
printf("addre==%u\n",&f.a);
printf("addre==%u\n",&f.b);
printf("addre==%u\n",&f.c);
printf("addre==%u\n",&f.d);

typedef struct _varia
{
 char a;
 char b;
 char c;
 char d;
}varia;
 varia s1;

printf("size of%d\n",sizeof(s1));
printf("addre==%u\n",&s1.a);
printf("addre==%u\n",&s1.b);
printf("addre==%u\n",&s1.c);
printf("addre==%u\n",&s1.d);
}
