#include<stdio.h>
main(argc,argv)
 
int argc;
char *argv[];
{
  printf("Before ecec mmy ID is %d \n",getpid());
  printf("Chil
  printf("exec starts\n");
  execl(argv[1],argv[2],argv[3],argv[4],(char *)0);
  printf("this will not print\n");

}
