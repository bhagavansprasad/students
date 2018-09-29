#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int Set_Random(int, int);
int arr[MAX];
main()
{
 int i,a;
for(i=0;i<=MAX;i++)
{
 a=Set_Random(0,MAX);
 printf("%d\t",a);
 
 }
}


int Set_Random(int min, int max)
{
 int init=0,valu=0;
 if(init == 0)
  {
    init=1;
  }
  valu=(random()% (max-min-1)+min);
  return (valu);
 					
}
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main (int argc, char *argv[])
{

  int k = time(NULL);
  srand (k);
 printf("num%d\n",k);
  int i;
  for (i=0; i<5; i++)
  {
    printf ("rand[%d]= %u\n",i,rand());
  }
  return 0;
}*/
