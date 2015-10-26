#include<stdio.h>
 
int min(int x, int y)
{
  int val =0;
  val = y ^ ((x ^ y) & -(x < y));
  printf("min-->=%d\n",val);
}
 
int max(int x, int y)
{
  int val=0;
  val = x ^ ((x ^ y) & -(x < y)); 
  printf("max-->=%d\n",val);
}
 
int main()
{
  int x = 10,y=11;
   min(x, y);
   max(x, y);
}

