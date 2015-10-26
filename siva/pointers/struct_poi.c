struct student
{
	char name[20];
	int id,marks;
}s1={"siva",100,80};
#include<stdio.h>
main()
{
	struct student *b;
	b=&s1;
	printf("%s\t%d\t%d\t",b->name,b->id,b->marks);
}


