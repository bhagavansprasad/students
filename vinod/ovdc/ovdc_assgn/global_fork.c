#include <stdio.h>
int a=10;

void parent();
void child();

int main()
{
	int p=0;
	p=fork();
	if(0==p)
		child();
	else
		parent();
	return 0;
}

void child()
{
	for(;;)
	{
		a++;
		printf("-->C: a :%d\n", a);
		printf("-->C: pid :%d	ppid :%d\n", getpid(), getppid());
		sleep(1);
	}
}

void parent()
{
	for(;;)
	{
		printf("-->P: a :%d\n", a);
		printf("-->P: pid :%d	ppid :%d\n", getpid(), getppid());
		sleep(1);
	}
}

