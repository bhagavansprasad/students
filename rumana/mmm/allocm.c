#include<stdio.h>
char buff[100];
int flag=0;
void* amalloc(int size);
void afree(char *s);
main()
{
	char *p1,*p2;
	p1=amalloc(100);
	printf("first pointer is :%p\n",p1);
	p2=amalloc(100);
	printf("second pointer is :%p\n",p2);
	afree(p1);
//	p2=amalloc(100);
//	printf("second pointer is :%p\n",p2);
	p1=amalloc(100);
	printf("first pointer is :%p\n",p1);
	afree(p2);
	afree(p2);
	p1=amalloc(100);	
	printf("first pointer is :%p\n",p1);
	afree(p1);
	afree(p1);
	p2=amalloc(100);
    printf("second pointer is :%p\n",p2);
	return(0);

}




void* amalloc(int size)
{
	if(flag==0)
	{
		flag=1;
		return (void *)buff;
	}
	else
	{
		return NULL;
	}
}


void afree(char *s)
{
   if(flag==1)
   {
    flag=0;
   }
   else
   {
    printf("error message\n");
   }
}
