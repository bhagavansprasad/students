#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#define N 4
int main()
{
	int t1,t2,p,i;
	p=getpid();                
	printf("root %d\n",p);
	fflush(stdout);
	for(i=1;i<N;i++) 
	{
		t1 = fork();
		if(t1!=0)
			t2 = fork();  
		if(t1!=0 && t2!=0)        
			break;      
	}
	printf("child pid %d   parent pid %d\n",getpid(),getppid());
	sleep(5);
	return 0;
}
