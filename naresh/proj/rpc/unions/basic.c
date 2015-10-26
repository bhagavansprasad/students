#include "stdio.h"

union naresh
{
int no;
char name[10];
int num;
};

main()
{
union naresh nar;

nar.no = 23;
printf("no : %d\n",nar.no);

strcpy(nar.name,"naresh");
printf("name : %s\n",nar.name);
printf("size of naresh :%d\n",sizeof(nar));

nar.num = 123;
printf("num :%d\n",nar.num);

}
