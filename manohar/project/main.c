#include<stdio.h>
#include"defs.h"
int p[2];
main()
{
  int pid;
  pipe(p);
  pid = fork();
  if(pid==0)
   {
     close(p[0]);
      for(;;)
       {
 
          ovd(p[1]);
          sleep(1);
   }
}
   else
   {
     
     close(p[1]);
      for(;;)
       {
          sleep(1);
          ovc(p[0]);
       }
   }
   return 0;
}
