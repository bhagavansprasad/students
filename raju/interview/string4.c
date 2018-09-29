#include<stdio.h>

main()
{
//	char c='A',cr[]="Hello";

//	char a='A',ar[]="Hello";

	char *p="Hello";
	int i=5;

	printf("%d \t %d\t %d\t %d\t %d\n",i,++i,i++,i++,i);

	printf("%c \t %c\t %c\t %c\n",*p,*++p,*p++,*p);

//	printf("c:%p\t a:%p\n",&c,&a);

//	printf("%p\t %p\t %p\t %p\n",&"Hello",&"Hello",cr,ar);

}	

