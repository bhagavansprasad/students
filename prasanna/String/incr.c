#include<stdio.h>
main()
{

	int i=5;
	char *p="hello";
	printf("%d %d %d  %d  %d\n",i,++i,i++,i++,i);
	printf("%d  %d  %d  %d\n",i++,++i,i++,++i);
	printf("%c %c %c %c\n",*p,*++p,*p++,*p);
}
