#include "stdio.h"
main()
{
union result
{
int marks;
char grade;
float per;
int sp;
};
union result res;
res.marks=95;
res.grade='d';
res.per=69.3;
res.sp=300;
printf("%d\n %c\n %f\n %x\n",res.marks,res.grade,res.per,res.sp);
printf("%d\n",sizeof(union result));

}
