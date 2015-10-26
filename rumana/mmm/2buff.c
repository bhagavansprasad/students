#include<stdio.h>
int buff1[100],buff2[100];
int flag1=0,flag2=0;
void* amalloc(int);
main()
{
char *p1[2],*p2[2];
p1[0]=amalloc(100);
printf("p1[0] is %p\n",p1[0]);
afree(p1[0]);
p1[1]=amalloc(100);
printf("p1[1] is %p\n",p1[1]);
afree(p1[1]);
p2[0]=amalloc(100);
printf("p2[0] is %p\n",p2[0]);
p2[1]=amalloc(100);
printf("p2[1] is %p\n",p2[1]);

}



void* amalloc(int size)
{
	if(flag1==0)
	{
      flag1=1;
	  return (void *)buff1;
	}
	else if(flag2==0)
	{
      flag2=1;
	  return (void *)buff2;
	}
	else
	return NULL;
}


int afree(void *p)
{
  printf("in free function");
	if(p==buff1)
	{
	printf("buff1 is %p\n",p);
     flag1=0;
	}
	 else if(p==buff2)
	 {
	 flag2=0;
	 printf("buff2 is %p\n",p);

	 }
	 else
	 printf("no memory");
}
