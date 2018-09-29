#include "stdio.h"
#include "stdlib.h"

void voc(int read_fd);
void ovd(int write_fd,int pid);

int main(int argc,char *argv[])
{
	int pid,i;
	int p1[2],arr[10];
	
	pipe(p1);
	
	if (argc<=1)
	{
		printf("the arguments not sufficient\n\r");
		exit(0);
	}
	
	printf("argc-->%d\n\r",argc);

	for( i = 0 ; i < argc ; i++ )
	{
	//	printf("argv -->%s\n\r",argv[i]);
		arr[i]=atoi(argv[i+1]);
	//	printf("arr[%d]-->%d\n\r",i , arr[i]);
		spliting(arr[i]);	
	}
		
void spliting(int arr)
{
	pid=fork();
	if(pid==0)
	{
		printf("i am child \n\r");
		close(p1[1]);
		ovc(p1[0]);
	}
	else
	{
		printf("iam parent\n\r");
		close(p1[0]);
		ovd(p1[1],arr[i]);
	}
}

