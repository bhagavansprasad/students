void my_function1(void)
{
	static int a=20;
	printf("---->a:%d\n",a);
	a++;
	printf("---->a:%d\n",a);
}
