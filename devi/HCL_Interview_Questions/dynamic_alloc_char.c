#include <stdio.h>
main()
{
	char c;
	c = malloc(100*sizeof(char));
	//c++;
	//char str[] = "hello";
	///strcpy(c,"hello");
	printf("%u\n",c);
	free(c);
}



/*--------->>>>>>>>>output<<<<<<<<----------------


Warnings:

implicit declaration of built-in function ‘malloc’
  c = malloc(100*sizeof(char));
      ^
assignment makes integer from pointer without a cast
  c = malloc(100*sizeof(char));
    ^
incompatible implicit declaration of built-in function ‘strcpy’
  strcpy("Helo\n",c);
  ^
passing argument 2 of ‘strcpy’ makes pointer from integer without a cast
expected ‘const char *’ but argument is of type ‘char’

incompatible implicit declaration of built-in function ‘free’
  free(c);
  ^
passing argument 1 of ‘free’ makes pointer from integer without a cast
expected ‘void *’ but argument is of type ‘char’
*/

