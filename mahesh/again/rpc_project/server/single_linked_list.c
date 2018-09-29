#include <stdio.h>
#include <malloc.h>
struct node
{
	int value;
	struct node *next;
};
struct node *h=NULL;
void addnode(int val)
{
	struct node *p,*new;
	new = malloc(sizeof(struct node));
	new->value = val;
	new->next = NULL;
	if(h==NULL)
	{
		h = new;
		return;
	}
	for(p=h;p->next != NULL; p=p->next);
	p->next = new;
}
void display()
{
	struct node *p;
	for(p = h;p!= NULL;p=p->next)
		printf("node value is : %d\n",p->value);
}
int get_first()
{
	struct node *p = h;
	return(p->value);
}
int get_last()
{
	struct node *p;
	for(p=h;p->next!=NULL;p=p->next);
	return(p->value);
}
int get_prev(int val)
{
	struct node *p,*q;
	for(p = h;p!=NULL;p=p->next)
	{
		q = p->next;
		if(q->value == val)
			return (p->value);
			
	}
}
int get_next(int val)
{
	struct node *p,*q;
	for(p = h;p!=NULL;p=p->next)
	{
		q=p->next;
		if(p->value == val)
			return (q->value);
	}
}
void linked_list_init()
{
	int i,first,last,pre,next;
	for(i=10;i<=50;i=i+10)
		addnode(i);
//	display();
//	first = get_first();
//	pre = get_pre(20);
//	next = get_next(20);
//	last = get_last();
//	printf("first : %d\n",first);
//	printf("pre : %d\n",pre);
//	printf("next : %d\n",next);
//	printf("last : %d\n",last);

}
int fact(int val)
{
	int i , f=1;
	for(i=1;i <= val;i++)
		f=f*i;
	return f;
}
int get_fact(int a,int b,int c)
{
	int f1,f2,f3;
	f1 = fact(a);
	f2 = fact(b);
	f3 = fact(c);
	return (f1+f2+f3);
}
