#include<stdio.h>
#include <string.h>
union team 
{
	char *name;
	int members;
	char captain[20];
};

int main()
{
	union team t1,*sptr;
	sptr = &t1;

	t1.name = "India";
	printf("1st : %s\n",t1.name);
	printf("1st : %s\n",sptr->name);
	printf("1st : %s\n",(*sptr).name);

    strcpy(sptr->captain,"paidi");
	printf("\n2nd : %s\n",sptr->captain);
	printf("2nd : %s\n",(*sptr).captain);
	return 0;
}
