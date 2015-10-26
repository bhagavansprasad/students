#include <stdio.h>
int main()
{
	long i;
	printf("process id is : %d\n",getpid());
	for(i=0 ; i <= 4000000 ; i++);
	printf("%d\n",i);
}
