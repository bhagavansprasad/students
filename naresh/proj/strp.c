#include "stdio.h"
#include "string.h"
struct stud
{
int no;
char *p;
char name[32];
};
main()
{
struct stud s1,*sp;
sp=&s1;
sp->no=10;
strcpy(sp->name,"naresh");

printf("name:%s\n",sp->name);
printf("no:%d\n",sp->no);
return 0;
}
