#include <stdio.h>
int main()
{
char array[7]={0,1,2,3,4,5,6};
int n;
printf("enter a number:%d\n",array[3]);
switch(array[3])
{
case 0:printf("violet\n");
       break;
case 1:printf("indigo\n");
       break;
case 2:printf("brown\n");
       break;
case 3:printf("green\n");
       break;
case 4:printf("yellow\n");

       break;
case 5:printf("orenge\n");
       break;
default:printf("red\n");
       break;
}
}
