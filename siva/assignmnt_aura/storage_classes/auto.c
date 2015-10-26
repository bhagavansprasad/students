#define auto2
#ifdef auto1
main()
{
auto int a = 10;
	auto int b;

	printf("-->a :%d\r\n", a);
	printf("-->b :%d\r\n", b);
}
#endif

#ifdef auto2
main()
{
int a = 10;
	int b;

	printf("-->a :%d\r\n", a);
	printf("-->b :%d\r\n", b);
}
#endif
