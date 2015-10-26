#include<stdio.h>
main()
{
	int a[5]={10,20,30,40,50};
	char g[]="Aura Networks";
	int b,c,size,size1;
	b=(&a+1);
	printf("b:%d\n",b);
	c=0;
	printf("c:%d\n",c);
	size=b-c;
	size1=(&a)[1]-a;
	printf("size:%d\n",size);
	printf("size1:%d\n",size1);
	b=(&g+1);
	c=g;
	size=b-c;
	size1=(&g)[1]-g;
	printf("size:%d\n",size);
	printf("size1:%d\n",size1);


}	
	


