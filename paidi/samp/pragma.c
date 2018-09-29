#include <stdio.h>
/*struct name
{
 int a;
 char h[1];
}x;
struct name b;
printf("size-->= %d\n",sizeof(b));*/
/*#pragma pack
struct name
{
int a:10;
int b:20;
char c;
};

int main()
{
// struct name b={10,20,3};
 struct name b;
printf("size of S = %d\n", sizeof(b));
}

*/
#pragma
main()
{
struct name
{
 int a;
 char b;
 short c;
 char d;

 };
 struct name f1={10,20,30,40};
 printf("size         :%d\n",sizeof(f1));
 printf("addres       :%u\n",f1.a);
 printf("addres       :%u\n",f1.b);
 printf("addres       :%u\n",f1.c);
 printf("addres       :%u\n",f1.d);
 
 }

