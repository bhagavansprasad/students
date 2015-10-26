#include <stdio.h>
int main()
{
  int arr[] = {3,4,5,6,7};
  
  int *ptr = arr;
  printf("sizeof(&arr) %ld sizeof(arr) %ld\n",sizeof(&arr),sizeof(arr));
  
  int (*p) [5]= &arr;
  printf("sizeof(p) %ld sizeof(*p) %ld \n",sizeof(p),sizeof(*p));

}
