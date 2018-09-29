#include<stdio.h>
int main(void)
 {
//int static i=9;
int static i=9;
printf("%d \n",i--);
if(i)
main();
return 0;
}
