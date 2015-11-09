#include <stdio.h>
union number
{
	int num;
	char a[4];
};
main()
{
	union number s;
	{
		s.num=300;
		int k;
		for (k=0;k<4;k++)
		printf("%d\n",s.a[k]);
		}
}


