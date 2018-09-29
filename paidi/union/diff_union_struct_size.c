#include <stdio.h>
union job   //defining a union
{         
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1 
{
	char name[32];
	float salary;
	int worker_no;
}s;

int main()
{
	printf("size of union = %d",sizeof(u));
	printf("\nsize of structure = %d\n", sizeof(s));
	return 0;
}
