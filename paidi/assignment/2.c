#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<unistd.h>

typedef struct name
{
 char *str[4];
}name;
main()
{
  int i,num=1;
	name string ={"creat_file a.txt",
		"add_string",
		"delet_file"
		"Disply",
	};
 
	for(i=1;i<=3;i++)
	{
	   
	   if (str == add)
	   	cmd = 1;
	   if (str == del)
	   cmd = 2;
	   my_function(string.str[i],num);
	   num++;
	}
}
my_function(char *arr,int cmd)
{
       int fd=-1,fd1=0,	retval;
       char buff[50]="paidi kumar";
        switch(num)
		{
			case 1:
			    fd = creat("t.txt",O_CREAT|0777);
                fd1= open("t.txt",O_RDWR);    
                if(fd1== -1)
                 {
                   perror("file will be not open\n");
                   exit(0);
                 }
				 break;
			case 2 :
				retval = write(fd1,buff,strlen(buff));
				printf("write\n");
				break;
			case 3 :
				retval = read(fd1,buff,strlen(buff));
				printf("read\n");
				printf("retval-->=%d\n",retval);
				break;

			case 4 :
				printf("delet\n");
				system("rm -rf t.txt");
				break;

			default :printf("iam in default case\n");
		}


}
