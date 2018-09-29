#include <stdio.h>
int a=10;
void my_fun1(void);
void my_fun2(void);
void my_fun3(void);
int new_fun(void);
int main()
{
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
my_fun1();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
my_fun2();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
my_fun1();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
new_fun();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
my_fun2();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
new_fun();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
my_fun3();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
my_fun3();
printf("\nfrom main()\n");
printf("----->aa :%d\r\n", a);
return 0;
}

void my_fun1(void)
{
printf("\nfrom fun1()\n");
printf("----->a :%d\r\n",a);
a++;
printf("----->a :%d\r\n", a);
}


void my_fun2(void)
{
int a = 20;

printf("\nfrom fun2()\n");
printf("----->aa :%d\r\n", a);
a++;
printf("----->aa :%d\r\n", a);
}

void my_fun3(void)
{
int a = 30;
printf("\nfrom fun3()\n");
printf("----->a :%d\r\n", a);
a++;
printf("----->aa :%d\r\n", a);
return a;
}
