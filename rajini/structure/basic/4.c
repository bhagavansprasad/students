#include <stdio.h>
#include <string.h>
struct stu
{
char a;
char b;
char c;
char d;
short int e;
short int f;
int g;
float h;
};
int main()
{
struct stu stu1;
printf("%d\n",sizeof(struct));
printf("a=%d\nb=%d\nc=%d\nd=%d\ne=%d\nf=%d\ng=%d\nh=%d\n",sizeof(stu1.a),sizeof(stu1.b),sizeof(stu1.c),sizeof(stu1.d),sizeof(stu1.e),sizeof(stu1.f),sizeof(stu1.g));
printf("%u\n%u\n%u\n%u\n%u\n%u\n%u\n%u\n",&stu1.a,&stu1.b,&stu1.c,&stu1.d,&stu1.e,&stu1.f,&stu1.g,&stu1.h);
return 0;
}

