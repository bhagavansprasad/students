#include <stdio.h>
 main()
{
	typedef struct name
	{
		int data;
		int num;
                char d;
                char e;
                int c;
	}data_name;
	data_name *a = 0;
	a++;
	printf("struct size------->= %d\n",a);
}


/*
main()
{
 struct name
{
 int a;
int b;
};
struct name *a=0;
a++;
printf("%d\n",a);

}

*/
