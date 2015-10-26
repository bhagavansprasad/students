#include <stdio.h>
main()
{
int arr[3] = {1,3,4};
char *p;
p = arr;
p = (char*)((int *)p);
printf("%d\n", *p);
p = (int*)(p+1);
printf("%d\n", *p);

}
