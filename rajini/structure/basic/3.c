#include <stdio.h>
#include <string.h>
struct books
{
 int a;
 int b;
 char name;
 char c;
 float per;
 };
 int main()
 {
 struct books book1;
 printf("total----%d\n",sizeof(struct books));
 printf("a-----%ld\n",sizeof(book1.a));       
   printf("b-----%ld\n",sizeof(book1.b));       
   printf("c-----%ld\n",sizeof(book1.name));       
   printf("d-----%ld\n",sizeof(book1.c));
   printf("d-----%ld\n",sizeof(book1.per));
   printf("&a-----%u\n",&(book1.a));       
   printf("&b-----%u\n",&(book1.b));       
   printf("&name-----%u\n",&(book1.name));       
   printf("&c-----%u\n",&(book1.c));       
   printf("&d-----%u\n",&(book1.per));
   return 0;
   }

