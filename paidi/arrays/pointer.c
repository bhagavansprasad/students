#include <stdio.h>
int data1=1;
char array1[10];
int data2;
int data3=3;
int data4;
short sh1;
short sh2=2;
int array2[10]={1,2};
short sh3;
short sh4=4;
char ch1=1;
char ch2;
short array3[10]={5,6};
char ch3=3;

void main()
{
	int ldata1;
	int ldata2=2;
	int ldata3;
	static int sdata1;
 static int sdata2=2;
 int*p=malloc(10);

printf("data1   \t= %u\n",&data1);
printf("array1  \t= %u\n",array1);
printf("data2   \t= %u\n",&data2);
printf("data3   \t= %u\n",&data3);
printf("data4   \t= %u\n",&data4);
printf("sh1     \t= %u\n",&sh1);
printf("sh2     \t= %u\n",&sh2);
printf("array2  \t= %u\n",array2);
printf("sh3     \t= %u\n",&sh3);
printf("sh4     \t= %u\n",&sh4);
printf("ch1     \t= %u\n",&ch1);
printf("ch2     \t= %u\n",&ch2);
printf("array3  \t= %u\n",array3);
printf("ch3     \t= %u\n",&ch3);


printf("ldata1  \t= %u\n",&ldata1);
printf("ldata2  \t= %u\n",&ldata2);
printf("ldata3  \t= %u\n",&ldata3);
printf("sdata1  \t= %u\n",&sdata1);
printf("sdtat2  \t= %u\n",&sdata2);
printf("p       \t= %u\n",&p);
}
void fun1()
{
 printf("i am function1\n");
 }
 void fun2()
 {
 printf("i am function2\n");
 }
 void fun()
 {
  printf("i am function3\n");
 }
