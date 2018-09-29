#include <stdio.h>
int main()
{
	char str = "A";
	//str = str+1;
	
	printf("str : %s\n", str);
	char str1[] = "abcd";
	char str2[6] = {'a','b','c','d','\0'};
	char str3[10] = "abcd";
	printf("%d %d %d %d\n", sizeof(str1), sizeof(str2), sizeof("abcd"),
	sizeof(str3));
	return 0;
}
