#include<stdio.h>
main()
{
 char*msg1="helloworld#1";

 char*msg2="helloworld#1";
 char*msg3="helloworld#1";
 char inbuf[16];
 int p[2],j;
 
 pipe(p);
 write(p[1],msg1,16);
 write(p[1],msg2,16);
 write(p[1],msg3,16);
 for(j=0;j<3;j++)
 {
  read(p[0],inbuf,16);
  printf("%s\n",inbuf);
  }
  }
