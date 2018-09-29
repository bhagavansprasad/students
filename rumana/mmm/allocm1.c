#include<stdio.h>
char buff[3][100];
int flag[3]={0};
void* amalloc(int size);
int afree(void*);
main()
{
	char *p1[3] ,*p2[3];
	int i;
	for(i = 0; i<3; i++)
   	printf("buff[%d] :%p\n",i,buff[i]);

	p1[0]=amalloc(100);
	printf("p1[0] is %p\n",p1[0]);
	
	//afree(p1[0]);
	
	p1[1]=amalloc(100);
	printf("p1[1] is %p\n",p1[1]);
	
	//afree(p1[1]);
	
	p1[2]=amalloc(100);
	printf("p1[2] is %p\n",p1[2]);
	
	p2[0]=amalloc(100);
	printf("p2[0] is  %p\n",p2[0]);
	
	afree(p1[2]);
	
	p2[1]=amalloc(100);
	printf("p2[1] is %p\n",p2[1]);

}




void* amalloc(int size)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			return ((void*)buff[i]);
		}
	}
	return NULL;
}


int afree(void *p)
{ 
	printf("\n\treseved addres is %p\n ", p);
	int i;
	for(i=0;i<3;i++)
	{
		if(p == buff[i])
		{
			flag[i]=0;
			return 0;

		}
		
	}
	printf("no memory to free");
}
