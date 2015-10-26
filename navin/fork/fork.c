#include <unistd.h>
#include <stdio.h>

int main()
{
  pid_t  pid;
  const char *name;

  pid = fork();
  if (pid == 0)
  {
      name = "I am the child";
     printf("%s\n",name);
  }
  else
  {
      name = "I am the parent";
      printf( "%s\n",name);
  }
  return 0;
}
