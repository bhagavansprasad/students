#include<stdio.h>

main()
{
int size=0,i;
char *p;
char *p1[10];
int buff[3][2]={{100,2},
                {200,3},
				 {300,5}};
 for(i=0;i<3;i++)
 {
size=size+buff[i][0]*buff[i][1];
 }
 printf("Size :%d\n",size);
 p=malloc(size);
 printf("Size of P :%d\n",p);
 p1[0]=&buff;
 printf("p1[0] is :%u\n",p1[0]);
 p1[1]=&buff[100];
 printf("p1[1] is :%u\n",p1[1]);
 p1[2]=&buff[200];
 printf("p1[2] is :%u\n",p1[2]);
 p1[3]=&buff[400];
 printf("p1[3] is :%u\n",p1[3]);
 p1[4]=&buff[600];
 printf("p1[4] is :%u\n",p1[4]);
 p1[5]=&buff[900];
 printf("p1[5] is :%u\n",p1[5]);
 p1[6]=&buff[1200];
 printf("p1[6] is :%u\n",p1[6]);
 p1[7]=&buff[1500];
 printf("p1[7] is :%u\n",p1[7]);
 p1[8]=&buff[1800];
 printf("p1[8] is :%u\n",p1[8]);
 p1[9]=&buff[2100];
 printf("p1[9] is :%u\n",p1[9]);
}

