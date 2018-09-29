#include<stdio.h>
#include<fcntl.h>
main()
{
  int fd,len=10,r=1,n=50,s=0;
  
  char buf[n];
 
 fd=open(" pattern.c",O_RDONLY,0);
 
 while(1)
 
 {
   
    r=read(fd,buf,len);

	 s+=r;

     printf("%s",buf);

	 if(r<n)
	
	break;

}

n=+10;
	
	close(fd);

}

