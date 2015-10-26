#include <stdio.h>
int main(argc,argv)
int argc;
char *argv[];
{
int i;
for(i=0;i<argc;i++)
  printf("argument is %s\n",argv[i]);
}  
