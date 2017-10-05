#include <stdio.h>
#include <string.h>

main()
{
	typedef union
	{
		int a;
		char b[10];
		float c;
	}
	Union;
	Union x = {100}, y = {100};

	printf("Union x : %d %s %f \n",x.a, x.b, x.c);

	x.a = 50;
	strcpy(x.b,"hello");
	x.c = 21.50;
	printf("Union x : %d %s %f \n",x.a,x.b,x.c);
	printf("Union y : %d %s %f \n",y.a,y.b,y.c);
}
