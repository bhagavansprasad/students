struct student
{
	char name[20];
	int id,marks;
}s1={"siva",100,80};
#include<stdio.h>
main()
{
	//struct student *b;
	fun(&s1);
  printf("function values printed\n");
	//printf("%s\t%d\t%d\t",b->name,b->id,b->marks);
}
fun(struct student *s)
{
	printf("%s\t%d\t%d\t",s->name,s->id,s->marks);
}

