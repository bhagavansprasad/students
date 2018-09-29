#include"stdio.h"
char var[]="sudheer";
int funct(int *n)
{
	int i;
	for(i=0;i<9;i++);
	{
		printf("%p\n",var[i]);
	}
}
main()
{
printf("%x",*var);
	funct(var);
	printf("%x\n",*var);
}
