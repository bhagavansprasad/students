#include <stdio.h>
#include <stdlib.h>
struct student
{
	int val;
	struct student *N;
};
struct student *h1=NULL;

struct student1
{
	int val;
	struct student *N;
};
struct student *h2=NULL;


main()
{
	int a[]={5,4,3};
	int b[]={2,3,4};
	int i,j;
	add_node1(a[i]);
	display_l1();
	printf("\n");
	add_node2(b[j]);
	display_l2();
	printf("\n");
}

int add_node1(int n)
{
	struct student *p,*t;
	p=malloc(sizeof(struct student));
	p->val=n;
	p->N=NULL;
	if(h1==NULL)
	{
		h1=p;
		return 0;
	}
	for(t=h1;t->N!=NULL;t=t->N);
	t->N=p;
	return 0;
}
int add_node2(int n)
{
	struct student *p,*t;
	p=malloc(sizeof(struct student));
	p->val=n;
	p->N=NULL;
	if(h2==NULL)
	{
		h2=p;
		return 0;
	}
	for(t=h2;t->N!=NULL;t=t->N);
	t->N=p;
	return 0;
}

int display_l1()
{
	struct student *t;
	printf("a=");
	for(t=h1;t!=NULL;t=t->N)
	{
	printf("%d",t->val);
	}
	return 0;
}
int display_l2()
{
	struct student *t;
	printf("b=");
	for(t=h2;t!=NULL;t=t->N)
	{
	printf("%d",t->val);
	}
	return 0;
}



