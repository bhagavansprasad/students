#include <stdio.h>
int main()
{
	char arr[]="this is excellent book for attending";
	char tar[80];
	char *x,*y;
	x = arr;
	y = tar;
	while(*y++ =*x++);
	printf("assigned      :%s\n",tar);
}
