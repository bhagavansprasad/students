#define USER_PROG

#define MAX 5
int main()
{
	for(i=0;i<MAX;i++)
	{
#ifdef USER_PROG
		print(i)
#endif
	}
	return 0;
}

