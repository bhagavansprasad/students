#include<stdio.h>
struct student
{
	int number;
	char name[6];
	char department[6];
	char course[6];
	int year;
};
main()
{
	struct student s[3]=
		{1,"siva","cse","BE",2006,
		2,"ravi","MEC","BE",2009,
		3,"pancl","MCA","PG",2010};
	int i;
        for(i=0;i<3;i++)
        
	details(s[i].year);
printf("%d\t%s\t%s\t%s\t",s[i].number,s[i].name,s[i].department,s[i].course);
}
int details(int n)
{

		if(n=2006)
		{
			return;
		}
}
