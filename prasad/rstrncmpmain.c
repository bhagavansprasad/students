#include"stdio.h"
#include"utils.h"
main()
{
  int n;
  char str1[]="PRASAD";
  char str2[]="PRASAD";
  n=rstrncmp(str1,str2,2);
  if(n==0)
  printf("THE Strings are equal");
  printf("n=%d \r\n",n);
}
