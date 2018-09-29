#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *p1 = "paidi";
	char *p2;
  	p2 = malloc(20);
	memset(p2,'p',5);
	//while(*p2++ = *p1++);
//	printf("%d\n",*p2);
	printf("p2       :%s\n",p2);
}
#if 0
int main()
{
	char *p1 = "paidi";
	char *p2;
  	p2 = malloc(20);
	printf("sizeof(p2)       :%d\n",sizeof(p2));
	printf("sizeof(*p2)      :%d\n",sizeof(*p2));
	
	strcpy(p2,p1);
	printf("string(p2)       :%s\n",p2);
}
#endif
