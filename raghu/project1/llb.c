#include <stdio.h>
#include <stdlib.h>
//struct student1 *reverse(struct student1 *h1);
struct student1
{
	int val;
	struct student1 *N;
};
struct student1 *h1=NULL;

struct student2
{
	int val;
	struct student2 *N;
};
struct student2 *h2=NULL;

main()
{
	int a=543;
	int x,z;
	int t1=a;
	struct student1 *p1;
	while(a>0)
	{
		x=a%10;
		get_in1(1,x);
		a=a/10;
	}
	display_ll1();
//	p1=reverse(h1);
	struct student1 *next,*cur,*pre;
	pre=NULL;	
	cur=h1;
	while(cur!=NULL)
	{
	next=cur->N;
	cur->N=pre;
	pre=cur;
	cur=next;
	}
	h1=pre;

	display_ll1();

	printf("\n");
	int b=129;
	int y,w;
	int t2=b;
	while(t2>0)
	{
		y=t2%10;
		get_in2(1,y);
		t2=t2/10;
	}
	display_ll2();
}

int display_ll1()
{
	struct student1 *t;
	for(t=h1;t!=NULL;t=t->N)
	{
		printf("%d\n",t->val);
		printf("%u\n",t->N);
	}
	return 0;
}
int display_ll2()
{
	struct student2 *t;
	for(t=h2;t!=NULL;t=t->N)
	{
		printf("%d\n",t->val);
		printf("%u\n",t->N);
	}
	return 0;
}
int get_in1(int x,int n)
{
	struct student1 *p,*t,*t1;
	int i;
	p=malloc(sizeof(struct student1));
	p->val=n;
	p->N=NULL;
	if(h1==NULL)
	{
		h1=p;
		t=p;
		return 0;
	}
	else if(x==1)
	{
		p->N=h1;
		h1=p;
		return 0;
	}
	else
	{
		t=h1;
		for(i=1;i<(x-1);i++)
		{
			t=t->N;
		}
		t1=t->N;
		t->N=p;
		p->N=t1;
	}
	return 0;
}
int get_in2(int x,int n)
{
	struct student2 *p,*t,*t1;
	int i;
	p=malloc(sizeof(struct student2));
	p->val=n;
	p->N=NULL;
	if(h2==NULL)
	{
		h2=p;
		t=p;
		return 0;
	}
	else if(x==1)
	{
		p->N=h2;
		h2=p;
		return 0;
	}
	else
	{
		t=h2;
		for(i=1;i<(x-1);i++)
		{
			t=t->N;
		}
		t1=t->N;
		t->N=p;
		p->N=t1;
	}
	return 0;
}
/*struct student1 *reverse(struct student1 *h1)
{
	struct student1 *next,*cur,*pre;
	pre=NULL;	
	cur=h1;
	while(cur!=NULL)
	{
	next=cur->N;
	cur->N=pre;
	pre=cur;
	cur=next;
	}
	h1=pre;
	return h1;
}*/
