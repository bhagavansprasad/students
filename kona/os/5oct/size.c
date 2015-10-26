#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
  #if 0
  struct stat fi;
  stat("/", &fi);
  printf("%d\n", fi.st_blksize);
  #endif
  printf("%d\n",getpagesize());
  return 0;
}
