#include<stdio.h>
int data1=1;
char array[10];
int data2;
int data3=3;
int data4;
short sh1;
short sh2=2;
int array2[10]={1,2};
short sh3;
short sh4=4;
char ch1=1,ch2=2;
short array3[10]={5,6};
char ch3=3;
void main()
{
int ldata1;
int ldata2=2;
int ldata3;
static int sdata1;
static int sdata2=2;
int *p=malloc(10);

printf("data1 address %d\n",&data1);
printf("array address %u\n",array);
printf("data2 address %d\n",&data2);
printf("data3 address %d\n",&data3);
printf("data4 address %d\n",&data4);
printf("sh1 address %d\n",&sh1);
printf("sh2 address %d\n",&sh2);
printf("array2 address %d\n",array2);
printf("sh3 address %d\n",&sh3);
printf("sh4 address %d\n",&sh4);
printf("ch1 address %u\n",&ch1);
printf("ch2 address %u\n",&ch2);
printf("array3 address %d\n",array3);
printf("ch3 address %u\n",&ch3);
printf("ldata1 address %u\n",&ldata1);
printf("ldata2 address %u\n",&ldata2);
printf("ldata3 address %u\n",&ldata3);
printf("sdata1 address %u\n",&sdata1);
printf("sdata2 address %u\n",&sdata2);
printf("p address%d\n",&p);
}








