#include<stdio.h>
main()
{
int a[3][3] = { {1,4},{5,6}};
printf("----->a=%u\n",a);
printf("----->a[0]=%u\n",a[0]);
printf("----->a[1]%u\n",a[1]);
printf("----->a[1][0]=%u\n",a[1][0]);
printf("----->&a=%u\n",&a);
printf("----->&a[1]=%u\n",&a[1]);
printf("----->a[0]+0=%u\n",&a[1]+0);
printf("----->a[1]+1=%u\n",&a[1]+1);
printf("----->&a[0][1]=%u\n",&a[0][1]);
printf("----->&a+1=%u\n",&a+1);
}

