#include <stdio.h>
main()
{
char *tem[4];
tem[0]="ex2";
tem[1]="hello";
tem[2]="world";
tem[3]=(char *)0;
printf("iam parent my pid is %d\n",getpid());
execvp(tem[0],tem);
printf("this will not print\n");
}
