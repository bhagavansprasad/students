#include<string.h>
#include<stdio.h>

int main()
{
    char *str = "Foo"; 
	*str = 'b';
	printf("%c\n",*str);
}
