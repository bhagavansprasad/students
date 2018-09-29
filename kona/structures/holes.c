#include<stdio.h>
struct student
{
	 char c ;
	char d ;
	char p;
	short int b;
	char q;
};
struct student s={'e','s','c',257,'x'};
main()
{
	printf("size is %u\n",sizeof(s));
	printf("address of  char is %u\n----->size%d\n",&s.c,sizeof(s.c));
	printf("address of char is %u\n----->size%d\n",&s.d,sizeof(s.d));
	printf("address of char is %u\n----->size%d\n",&s.p,sizeof(s.p));
	printf("address of short int is %u\n---->size%d\n ",&s.b,sizeof(s.b));
	printf("address of char is %u\n---->size%d\n ",&s.q,sizeof(s.q));
	/*printf("address of char is %u\n",&(s.t));
	printf("address of char is %u\n",&(s.p));*/
char *p,*k;
int i;
for(i=0;i<4;i++,p++,k++)
{
p=(char*)&s.c+i;
k = (char*)&s.b+i;
printf("%u\n",p);
printf("%u\n",k);
printf("----> value:%d\n",*p);
printf("----> value:%d\nchar}

