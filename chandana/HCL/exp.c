#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* question 
int main()
{
char *c;
int *p;
c =(char *)malloc(100);
ip=(int *)c;
free(ip);
}
*/
int main()
{
	char *c;
	char *p;
	char *ip;
	c =(char *)malloc(100);
	strcpy(c,"Aura");
	printf("string      : %s\n",c);
	ip=(char *)c;
	printf("ip          :%s\n",ip);
	free(ip);
	printf("free        :%s\n",ip);
}
