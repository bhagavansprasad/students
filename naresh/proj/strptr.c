#include "stdio.h"
#include "string.h"
struct stud
{
int no;
struct stud *p;
};
main()
{
struct stud s1,s2,s3,*sp;
sp=&s1;

s1.no=10;
s2.no=20;
s3.no=40;
s1.p=&s2;
s2.p=&s3;
s3.p=NULL;

printf("s1 no:%d\n s2 no:%d\n s3 no:%d\n",sp->no,sp->p->no,sp->p->p->no);
printf("s1 p:%u\n s2 p:%u\n s3 p:%s\n",sp->p,sp->p->p,sp->p->p->p);
return 0;
}
