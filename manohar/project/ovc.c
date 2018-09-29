#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"errno.h"
#include"defs.h"
void ovc(int readfd)
{
   struct data y;
   int array[1000],retval=0;
    printf("this is the ovc process\n\r");
      for( ; ; )
{      printf("hi\n\r");
       retval = read(readfd,&y,sizeof(struct data));
           if(retval ==-1)
           {
             perror("read to fail");
             exit(0);
           }

      printf("\r\npid...%d giffies...%d\n\r",y.pid,y.giff); 
 


}    
 }
   
