#include <stdio.h>
main()
{
	char buff[4][15]={
						"aura network",
						"bangalore",
						"india"
					};
	printf("%u\n",buff);
	printf("%u\n",buff[1]);
	printf("%u\n",&buff);
	printf("%c\n",buff[1][1]);
	printf("%u\n",&buff[1][1]);
	printf("%u\n",buff+1);
	printf("%u\n",&buff+1);
	printf("%u\n",*&buff);
	printf("%u\n",**&buff);
	printf("%c\n",***&buff);
}
