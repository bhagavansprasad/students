#include <stdio.h>
main(argc,argv)
int argc;
char *argv[];
{
printf("iam child after execl my process id is %d\n",getpid());
printf("child is %s and its argument are:%s %s\n",argv[0],argv[1],argv[2]);
printf("exec ends\n");
}
