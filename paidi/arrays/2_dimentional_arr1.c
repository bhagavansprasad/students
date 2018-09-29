#include<stdio.h>
int main()
{
    int i,j;
    int arr[3][3] = {10,20,30,
	                 40,50,60,
					 70,80,90};
     /*arr[0][0] = 10;
       arr[0][1] = 20;
       arr[1][0] = 30;
       arr[1][1] = 40; 
       arr[2][0] = 50;
       arr[2][1] = 60; 
      */
    for (i=0;i<3;i++)
    {
       for (j=0;j<3;j++)
       {
          printf("value of arr[%d] [%d] : %d\n",i,j,arr[i][j]);
       }
    }
}
