#include<stdio.h>
#include <string.h>
main()
{
printf("%c\t","determination"[2]);
printf("%c\t",*("determination"+2));
printf("%s\t","determination"+2);
printf("determination"+2);
printf("\t");
printf("determination"+strlen("deepali"));
printf("\t");
printf("determination"+sizeof("deepali"));
printf("\n");
}
