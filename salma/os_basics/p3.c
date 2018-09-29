#include<stdio.h>
main()
{
 int p[2],pid;
 pipe(p);
 pid=fork();
 if(pid==0)
 printf("%d  %d this is child process\n",p[0],p[1]);
 else
 printf("%d %d this is parent process\n",p[0],p[1]);

}
