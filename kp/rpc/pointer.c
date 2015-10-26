#include<stdio.h>
#include<string.h>
main()
{
	int a=300;
	char *p = &a;
    //char c = 10;
	//char *d = &c;
	////c=a;
	//printf("a=%d\n",a);
	//printf("p=%d\n", sizeof(p));
	//printf("c=%d\n",sizeof(c));
	printf("p=%d\n",*(p+1));
	//printf("c=%u\n",&d);
	//p++;
	//d++;
	//printf("p=%u\n",&p);	
	//printf("c=%u\n",&d);

}

