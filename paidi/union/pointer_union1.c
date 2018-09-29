#include<stdio.h>
#include<string.h>
union address
{
	char *name;
	char street[10];
	int pin;
//}emp,*p;
};
int main()
{

//	union address emp;
	union address emp,*p;

	emp.name="paidi\0kumar";
	p=&emp;
	printf("1st-->= %s %s  %s\n",emp.name,(*p).name,p->name);

	strcpy(p->street,"Aura\0paidi");
	printf("2nd--->= %s %s \n",(*p).street,p->street);
	return 0;
}
