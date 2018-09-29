#include <stdio.h>
#include <stdlib.h>
struct emp
{
	int data;
	struct emp *next;
};

struct emp *f = NULL, *r = NULL;

int insert(int num);
void display();
void reverse();
int get_orderof_list(struct emp *p);

int main()
{
	int flag=0, pos=1;
	struct emp *p;
	
	insert(10);
	insert(8);
	insert(9);
	insert(2);
	insert(7);
	insert(6);
	insert(5);
	insert(4);
	insert(1);
	insert(3);
	insert(0);
	
	printf("----Ordered list----\n");
	
	display();
	
	for(p=f ; pos<11 && p->next!=f ; p=p->next,pos++);
	
	printf("----> Giving Node position : %d\n", pos);
	
	flag = get_orderof_list(p);
	
	if(flag == 0)
		printf("Given orderd circular list is in ascending order\n");
	else
		printf("Given orderd circular list is in descending order\n");
	
	reverse();
	
	printf("----Reverse Ordered list----\n");
	
	display();
	
	pos = 1;

	for(p=f ; pos<11 && p->next!=f ; p=p->next,pos++);
	
	printf("----> Giving Node position : %d\n", pos);

	flag = get_orderof_list(p);
	
	if(flag == 0)
		printf("Given orderd circular list is in ascending order\n");
	else
		printf("Given orderd circular list is in descending order\n");

	return 0;
}

int insert(int num)
{
	struct emp *t, *p;
	t = malloc(sizeof(struct emp));
	t->data = num;
	p = f;

	if((f==NULL && r==NULL))
	{
		f = t;
		t->next = f;
		r = f;
		return;
	}

	if(f->data >= num)
	{
		t->next = f;
		f = t;
		r->next = f;
		return;
	}
	
	for( ; p->next != f ; p=p->next)
	{
		if(p->data < num && p->next->data > num)
		{
			t->next = p->next;
			p->next = t;
			return;
		}
	}

	if(p->next == f)
	{
		p->next = t;
		t->next = f;
		r= t;
		return;
	}
}

int get_orderof_list(struct emp *p)
{
	struct emp *t;
	for(t=p ; t->next != p ; t=t->next);
	printf("t : data : %d, p : data : %d, p next data : %d\n", t->data, p->data,
	p->next->data);
	if((p->data < p->next->data && p->data > t->data) || ((p->data > p->next->data) && (p->data > t->data)))
		return 0;
	else
		return 1;
}

void reverse()
{
	struct emp *p,*q,*temp;
	r->next = NULL;
	temp = f;
	p = NULL;
	while(f != NULL)
	{
		q = p;
		p = f;
		f = f->next;
		p->next = q;
	}
	f = p;
	temp->next = f;
	r = temp;
}

void display()
{
	struct emp *p, *temp;
	temp = r;
	for(p=f ; p!=NULL ; p=p->next)
	{	
		printf("praddr -> %p data -> %d nxtaddr ->%p\n", p,p->data, p->next);
		if(p == r)
			return;
	}
}
