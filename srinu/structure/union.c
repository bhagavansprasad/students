#include <stdio.h>
union student
{
int marks;
char grade;
float per;
};
main()
{
union student u;
u.marks=78;
printf("%d\n",u.marks);
}

