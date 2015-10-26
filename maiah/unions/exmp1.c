#include "stdio.h"
union result
{
 	int marks;
 	char grade;
	float per;
};
main()
{
	union result res;
	res.marks=89;
	res.grade='A';
	res.per=88.56;
	printf("marks:%d\n grade:%c\n per:%f\n",res.marks,res.grade,res.per);
}
