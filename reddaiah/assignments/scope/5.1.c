int a=10;
main()
{
	printf("--->a:%d\r\n",a);
	my_function1();
	printf("--->a:%d\r\n",a);
	my_function2();
	printf("--->a:%d\r\n",a);
	new_fun();
	printf("-->a:%d\r\n",a);
	my_function2();
	printf("--->a:%d\r\n",a);
	new_fun();
	printf("--->a:%d\r\n",a);
	a=my_function3();
	printf("-->a:%d\r\n",a);
}
void my_function1();
{
	printf("-->a:%d\r\n",a);
	a++;
	printf("--->a:%d\r\n",a);
}
void my_function2(void)
{
	static int a=20;
	printf("--->a:%d\r\n",a);
	a++;
	printf("--->a:%d\r\n",a);
}
void my_function3(void)
{
 int a=30;
	printf("-->a:%d\r\n",a);
	a++;
	printf("-->a:%d\r\n",a);
}

