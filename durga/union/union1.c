#include <stdio.h>
struct stag
{
char ch;
int i;
float f;
};
union utag
{
char ch;
int i;
float f;
};
main()
{
struct stag s;
union utag u;
printf("------->asizeof struct:%d\n",sizeof(s));
printf("------->asizeof union:%d\n",sizeof(u));
printf("------->addreas of struct:%u\n",&s);
//printf("------->asizeof struct:%u\n",sizeof(s));
}
