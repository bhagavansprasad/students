#include<stdio.h>
main()
{
unsigned int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
printf("%u\t \n",a);
printf("%u\t \n",a+1);
printf("%u\t \n",a[1]);
printf("%u\t \n",a[1][2]);
printf("%u\t \n",&a[1]);
printf("%u\t \n",&a);
printf("%u\t \n",&a[1]+1);
printf("%u\t \n",&a+1);
printf("%u\t \n",&a[1][2]);
}
