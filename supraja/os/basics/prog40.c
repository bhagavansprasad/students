#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fp,pid;
	char buff[11];
	fp=open("baby",O_RDONLY);
	pid=fork();
	if(pid==0)
	{
		printf("file handle is %d\n",lseek(fp,01,1));
		read(fp,buff,10);
		buff[10]='\0';
		printf("file handle is now %d in the child process\n:",lseek(fp,01,1));
	}
	else
	{
		wait(0);
		printf("file handle in parent process is %d\n",lseek(fp,01,1));
	}
}
