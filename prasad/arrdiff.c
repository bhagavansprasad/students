#include"stdio.h"
main()
{
int a[5]={1,2,3,4,5};
int *p = &a[0];
int **p1 = &p;
int *ap[5];
int (*pa)[5];
/*printf("%u\r\n",p);
p++;
printf("%u\r\n",p);
printf("%u\r\n",p1);
p1++;
printf("%u\r\n",p1);
printf("address of a=%u \n",a);
printf("address of a+1=%u \n",a+1);
printf("address of &a+1=%u \n",&a+1);
printf("address of a[0]=%d \n",a[0]);
printf("address of p=%u \n",p);
printf("address of &p=%u \n",&p);
printf("address of &p+1=%u \n",&p+1);
printf("address of ap=%u \n",ap);
*/
printf("address of pa=%u \n",pa);
printf("address of pa+1=%u \n",pa+1);
printf("address of pa+2=%u \n",pa+2);
printf("address of &pa+1=%u \n",&pa+1);
//printf("address of &ap+1=%u \n",&ap+1);
printf("address of pa=%u \n",pa);
}
