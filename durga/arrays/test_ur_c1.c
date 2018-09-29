#include <stdio.h>
main()
{
int arr [] = {1,2,3,4,5};
int i;
i = ++arr[0];
printf("%d\n", i);
 i = arr[0]++;
 printf("%d\n",i);
 printf("%d\n",arr[i++]);
 printf("%d\n",i);
 printf("%d\n",arr[0]);
}
