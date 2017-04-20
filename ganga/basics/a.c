#include<stdio.h>
#define SIZE sizeof(int)

main()
{
	int i=-1;
	printf("%d\n", SIZE);
	if( i < SIZE )
		printf("True");
	else
		printf("False");
}
/*#include<string.h>
  void main()
  {
  char buff[100]="aura networks:";
  char buff1[100]="the _hello";
  char buff2[100];;
//int length=astrlen(buff);
//int cmp=astrcmp(buff1,buff2);
//printf("%d",length);
//printf("%d", cmp);
char cpy=*astrcpy(buff2,buff1);
printf("%s",cpy);
} */
