#include <stdio.h>
#include <stdlib.h>
char a[100];
char b[100];
char c[100];
int i = 1,j = 1,k = 1;

void *a_fun1(void *arg)
{
int k;
char *p = NULL;
p = amalloc(100);

if(p == NULL)
	printf("memory not allocated\n");
strcpy(p,"A-THREAD");
printf("%s\n",p);
k = free()
}

void *amalloc(int n)
{
if(i == 1)
{
	i == 0;
	return a;
}
else if(j == 1)
{
	j == 0;
	return b;
}
else if(k == 1)
{
	k == 0;
	return c;
}
else
	sleep(1);
}

main()
{
pthread_t at,bt,ct,dt,et;
int res;

res = pthread_create(&at,NULL,a_fun1,(void *)message1);
if(res != 0)
{
	perror("error in creating thread is \n");
	exit(1);
}


}
