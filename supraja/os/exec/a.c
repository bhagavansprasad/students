#include <stdio.h>
main(int argc,char *argv[])
{
if(argc>3)
   printf("more arguments\n");
else
   printf("%s %s",argv[0],argv[1]);
}   
