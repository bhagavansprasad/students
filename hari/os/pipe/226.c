#include<stdio.h>
#define msgsize 16
main()
{
 char*msg1="hello,world";
 char inbuf[msgsize];
 int p[2],j,pid;
 pipe(p);
 pid=fork();
 if(pid>0)
  write(p[1],msg1,msgsize);
 else
 {
  sleep(1);
  read(p[0],inbuf,msgsize);
  printf("%s\n",inbuf);
 }
 exit(0);
 }
