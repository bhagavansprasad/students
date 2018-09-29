#include<stdio.h>
#define MSGSIZE 20



int parent(int rfd, int wfd)
{ 
  int retval=0;
  char *msg1="hello,rajini#1";
  char pbuff[MSGSIZE];
 
 
  printf("P:::parent is going to write \n");
  retval=write(wfd,msg1,MSGSIZE);
  printf("P:::retval : %d\n",retval);
  
  printf("P:::after writing parent will exist.\n");
  printf("P:::parent is going to read...\n");
  
  retval=read(rfd,pbuff,MSGSIZE);
  
  printf("P:::after reading\n");
  printf("P:::buff%s\n",pbuff);
  printf("P:::parent is going to exist \n");
}

int child(int rfd, int wfd)
{
  int retval=0;
  char *msg2="hello,rajini#1";
  char cbuff[MSGSIZE];
  
  printf("C::child is going to read \n");
  retval=read(rfd,cbuff,MSGSIZE);
  printf("C::after reading..\n");
  printf("C::retval %d\n",retval);
  printf("c:cbuff %s \n",cbuff);
  
  printf("C::child is going to write..\n");
  retval=write(wfd,msg2,MSGSIZE);
  printf("C::child is going to exist \n");



}
main()
{
 char *msg1="hello,rajini#1";
 char buff[MSGSIZE];
 int pid,p1[2],p2[2];
 pipe(p1);
 pipe(p2);
 pid=fork();
 if(pid>0)
 {
   parent(p1[0],p2[1]);
 }
  else
  {
   child(p2[0],p1[1]);
  }
}
