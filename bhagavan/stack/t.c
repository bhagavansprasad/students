#define PRINT_VAR_ADDR(x) (printf("%10s\n", #x))
#define GET_CUBE_VALUE(x) (x*x*x)

main()
{
	int temp = 10;

	PRINT_VAR_ADDR(temp);
	printf("%d\n", GET_CUBE_VALUE(temp));
}
