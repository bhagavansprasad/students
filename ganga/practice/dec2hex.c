/*
#include<stdio.h>
int main()
{

unsigned int n = 17 ;

printf(" decimal number:%d\n ", n);

printf("Equivalent hexadecimal number is: %X\n", n);

return 0;
}
 */

#include<stdio.h>
int main()
{
	int dec = 10, remainder, quotient;
	int i = 1, j, temp;
	char hex[100];

	quotient = dec;

	while(quotient != 0)
	{
		temp = quotient % 16;
		//To convert integer into character
		if( temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;

		hex[i++] = temp ;
		quotient = quotient / 16;
	}

	printf("hexadecimal value of given decimal number is %3d\n ", dec);
	for(j = i - 1 ;j> 0;j--)
		printf("%c\n", hex[j]);
	printf("\n");

	return 0;
}
