#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


main()
{
  int fd,pid;
 
 
 char buff[1000] ;
 fd=open("1.txt",O_RDONLY);

pid=fork();


if(pid==0)
{

  read(fd,buff,15);
  printf("\nChild : \n%s \n",buff);
  printf("fd ---> %d \n ",fd);
  printf("pid ---> %d \n ",pid);

}
else
 {
  wait(10);
  read(fd,buff,20);
  printf("\nParent: \n%s \n",buff);
  printf("fd ---> %d \n ",fd);
  printf("pid ---> %d \n ",pid);
}




 // if(fd<0)
 // break;
// write(1,buff,50);

//}

// sleep(100);
}
