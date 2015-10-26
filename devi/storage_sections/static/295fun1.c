int my_fun1(int *q)
{
int c;
printf("from function");
printf("--->a :%d\r\n", *q);
*q=*q+1;
printf("--->a :%d\r\n", *q);
my_fun2();
return *q;
}
