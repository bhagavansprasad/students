#include<stdio.h>

int main()
{
	union abc
	{
		  short int a;
	  char b;
	     char c;
		//char d;
		//int e;
	}abc;
	printf("%d\n",sizeof(abc));
	printf("actuval size of short int is 2 bytes---a:%u\n\n",&abc.a);
	printf("actuval size of char is 1bytes---b:%u\n\n",&abc.b);
	printf("actuval size of short int is 2 bytes---c:%u\n\n",&abc.c);
	//printf("actuval size of char is 1 byte --->d:%u\n\n",&abc.d);
	//printf("actuval size of int is 4 bytes--->e:%u\n\n",&abc.e);
	//printf("%d\n\n",sizeof(abc.a));
    //printf("%d\n\n",sizeof(abc.b));
	//printf("%d\n\n",sizeof(abc.c));
	//printf("%d\n\n",sizeof(abc)-(sizeof(abc.a)+sizeof(abc.b)+sizeof(abc.c)));
    
}
