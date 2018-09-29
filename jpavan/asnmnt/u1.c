#define USER_PROG
# define MAX 5
main()
{
	for(i=0;i<=MAX;i++)
	{
#ifdef USER_PROG
		printf("i value is %d",i);
#endif
	}
}

