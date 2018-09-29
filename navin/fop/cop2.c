#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char *arg[])
{
	int fd,fd1,i,j,k,l,m;

	char buff[10000];

    m=atoi(arg[3]);  
    

	fd=open(arg[1],O_RDWR);
	if(fd==-1)
		printf("Error in opening file 1 \n");
	else 
		printf("File 1 openend successfully");

	fd1=open(arg[2],O_RDWR|O_CREAT);
	if(fd==-1)
		printf("Error in opening file 2 \n");
	else 
		printf("File 2 openend successfully");


//	i=read(fd,buff,10000);
	if(i==0)
		printf("\n noithing to write. File file is empty \n");
	else 
	{   

<<<<<<< cop2.c
       // l=arg[3];
	  	j=lseek(i,sizeof(arg[3]),SEEK_SET);
		printf("%d",j);
=======
       lseek(fd,m,SEEK_SET);
       write(fd1,buff,m);



	    printf("\n");
      //lseek(fd,i-m,SEEK_CUR);
	   lseek(fd,-10,SEEK_END);
>>>>>>> 1.2

<<<<<<< cop2.c
		write(fd1,buff,i);

		k=lseek(i,sizeof(arg[3]),SEEK_END);
		write(fd1,buff,k);
=======
	    write(fd1,buff,m);
>>>>>>> 1.2

		printf(" Successfully copied  character from file 1 at starting and ending :) \n",arg[3]);
	}

	close (fd) ;
	close (fd1);














}
