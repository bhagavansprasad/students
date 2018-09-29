#include <unistd.h>
#include <stdio.h>

int main()
{
  pid_t  pid1;
  int pid,ppid;
  pid=getpid();
  ppid=getppid();
  const char *name;

  pid1 = fork();
  if (pid1 == 0)
  {
      name = "I am the child";
     printf("I am the child\n");
	 printf("child->getpid-->=%d\n",pid);
	 printf("child->getppid-->=%d\n",ppid);
  }
  else
  {
      name = "I am the parent";
      printf( "I am the parent\n");
	 printf("parent->getpid-->=%d\n",pid);
	 printf("parent->getppid-->=%d\n",ppid);
  }
  return 0;
}
