#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
   int i,fd,val,s,nl,wr;
   char b[200];

   fd=open("r.txt",O_RDONLY);
     	while(1)
		{
		 val=read(fd,b,30);
		   b[val]='\0';
		  for(i=0;b[i]!='\0'; i++)
		     {
			     if(b[i]==' ')
			       {
			        	for( ;b[i]==' ';i++);
				         i--;   
			       }
			  
			      if(b[i]>=65 && b[i]<=122)
			       { 
				        wr++;
				        for( ;b[i]>=65 && b[i]<=122;i++);
				          i--;
			       }
				  if(b[i]=='\n')
				   {
				    nl++;
				   }  
               }
			     s=s+val;
			     if(val<30)
			       {
				   break;
			       }
		 }		   
         close(fd);
		  printf("nl:%d\n,s:%d\n,wr:%d\n",nl,s,wr);
	 
}
