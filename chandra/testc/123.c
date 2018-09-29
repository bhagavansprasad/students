#include<stdio.h>
//void f(struct emp);
struct emp
{
	char name[20];
	int age;
};
//struct emp e;
int main()
{
	struct emp e = {"chandra", 23};
	f(e);
	return 0;
}
void f(struct emp ee)
{
	printf("name is : %s age is : %d\n", ee.name, ee.age);
}

