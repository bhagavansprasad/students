#include "stdio.h"
#include "string.h"
struct student
{
 int no;
 char *p;
 char name[100];
};
main()
{
struct student s1,*sp;
sp=&s1;
sp->no=10;
strcpy(sp->name,"hello word");
sp->p=malloc(sizeof(struct student));
strcpy(sp->p,"hello word");
printf("%d\n",sp->no);
printf("%s\n",sp->name);
printf("%u\n",sp->name);
printf("%s\n",sp->p);
return 0;
}
