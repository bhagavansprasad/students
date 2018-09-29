#include <stdio.h>
main()
{
char *temp[3];
temp[0]="ls";
temp[1]="-l";
temp[2]=(char *)0;
//execv("/home/bhagavan/students/supraja/os/exec/a1",temp);
execv("/bin/ls",temp);
printf("this will not print\n");
}
