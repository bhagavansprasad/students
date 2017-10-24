#include <stdio.h>
#include <string.h>
main()
{
	char *arr[5];
	puts(arr);
	func1(arr);
	puts(arr);
	func2(arr);
}
void func1(char x[])
{
	x="jack";
	puts(x);
}
void func2(char x[])
{
	x[0]='j',x[1]='i',x[2]='l',x[3]='l',x[4]='\0';
	puts(x);
}
