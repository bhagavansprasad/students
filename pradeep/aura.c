#include <stdio.h>
#include <string.h>
union student
{
	int a;
	char array[3];
};
main()
{
int i;
	union student s1;
	s1.a=300;
	printf("%d\n",s1.a);
	for(i=0;i<sizeof(s1);i++)
	{
		printf("%d\n",s1.array[i]);
	}
}
