#include <stdio.h>
#include <string.h>
struct books
{
   char a;
   short int b;
   char c;
   int d;
};
int main()
{ 
   struct books book1;
 //  printf("%d\n",sizeof(int));
   printf("total--%d\n",sizeof(struct books));
//   strcpy(book1.title,"c programming");
  // strcpy(book1.author,"dennis richi");
 //  strcpy(book1.subject,"c basics");
  // book1.rollno=405;
   printf("a-----%ld\n",sizeof(book1.a));       
   printf("b-----%ld\n",sizeof(book1.b));       
   printf("c-----%ld\n",sizeof(book1.c));       
   printf("d-----%ld\n",sizeof(book1.d));
   printf("&a-----%u\n",(book1.a));       
   printf("&b-----%u\n",(book1.b));       
   printf("&c-----%u\n",(book1.c));       
   printf("&d-----%u\n",(book1.d));
   return 0;
}
