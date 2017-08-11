#include<stdio.h>
main()
{
	union employee
	{
		char name[20];
		int id;
		char position[15];
	};
//	union employee emp1;
	union employee emp2={"rinju",12,"bapi"};
/*	strcpy(emp1.name,"bapi");
	printf("%s ",emp1.name);
	emp1.id=23;
	printf("%d ",emp1.id);
	strcpy(emp1.position,"swe");
	printf("%s ",emp1.position);*/
	printf("%s %d %s",emp2.name,emp2.id,emp2.position);
	printf(" %d ",sizeof(emp2));
}
