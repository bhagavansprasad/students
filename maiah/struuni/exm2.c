#include "stdio.h"
#include "string.h"
struct stu
{
	int a,b;
	struct stu *p;
};
main()
{
	struct stu s1={10,20};
    struct stu *p=&s1;
 	s1.p=malloc(sizeof(struct stu));
	printf("%d\n %d\n",p->a,p->b);
	return 0;
}
