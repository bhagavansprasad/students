static int a = 10;
static void my_fun2(void);
main()
{
int p;
printf("from main\n");
printf("--->a :%d\r\n", a);
my_fun2();
printf("from main\n");
printf("--->a :%d\r\n", a);
my_fun1(&a);
my_fun2();
printf("from main\n");
printf("--->a :%d\r\n", a);
}

static void my_fun2(void)
{
printf("from fun\n");
printf("--->a :%d\r\n",a);
a++;
printf("from fun\n");
printf("--->a :%d\r\n", a);
//return *a;
}
