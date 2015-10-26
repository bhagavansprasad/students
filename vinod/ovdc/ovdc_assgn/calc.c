#include <stdio.h>
#include <string.h>

int add_numbers(char *, char *);
int sub_numbers(char *, char *);
int mul_numbers(char *, char *);
int div_numbers(char *, char *);

int main(int argc, char *argv[])
{
	int retval = 0;
	int a=0,b=0;
	char str[10];

	a = atoi(argv[2]);
	b = atoi(argv[3]);

	printf("a -> %d\nb -> %d\n", a, b);

//	strcpy(str, argv[1]);
	
	if(strcmp("add",argv[1]) == 0)
	{
		retval = add_numbers(argv[2], argv[3]);
		printf("Addition -> %-3d + %3d = %3d\n", atoi(argv[2]), atoi(argv[3]), retval);
	}
	else if(strcmp("sub", argv[1]) == 0)
	{
		retval = sub_numbers(argv[2], argv[3]);
		printf("subtraction -> %3d - %-3d = %3d\n", atoi(argv[2]), atoi(argv[3]), retval);
	}
	else if(strcmp("mul",argv[1]) == 0)
	{
		retval = mul_numbers(argv[2], argv[3]);
		printf("Multiplication -> %3d * %-3d = %3d\n", atoi(argv[2]), atoi(argv[3]), retval);
	}
	else if(strcmp("div",argv[1]) == 0)
	{
		retval = div_numbers(argv[2], argv[3]);
		printf("Division -> %3d / %-3d = %3d\n", atoi(argv[2]), atoi(argv[3]), retval);
	}
	else
		printf("Entered different command\n");
	return 0;
}
