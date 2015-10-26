#include<stdio.h>
main()
{
	char str[15] = "Aura Networks";

	printf("str = %u and val = %s\n", str,str);
	printf("&str = %u and val = \n", &str);
	printf("str+1 = %u and str+1 = %s\n", str+1, str+1);
	printf("&str+1 = %u and val = %s\n",&str+1, &str+1);
	printf("*&str = %u and val = %s\n", *&str, *&str);
	printf("*str = %c and \n", *str);
	printf("**&str = %c\n", **&str);
}
