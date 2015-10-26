#include <stdio.h>
#include <fcntl.h>
main()
{
   printf("word count for [] = %d\n", wordcount("./prasad.txt"));
}

int wordcount(char *str)
{
   int fd;
   int ind =0;
   int wcount =0;
   char wflag = 0;
   char buf[1];
   fd = open(str, O_RDONLY); 
   read(fd,&wflag,1);
   while( read(fd,buf,1) == 1 )
   {
     printf("%c", buf[0]);
      if( buf[0] == ' ' || buf[0] == '\n')
      {
        if(wflag != 0)
        {
           wflag =0;
           wcount ++;
        }
      }
      else
      {
         wflag ++;
      }
   }
   if(wflag != 0)
   {
      wcount ++;
   }
   return wcount;
}
