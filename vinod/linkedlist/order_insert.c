#include <stdio.h>
#include <stdlib.h>
struct emp
{
	int data;
	struct emp *next;
};

struct emp *h = NULL;
int insert(int num);
void display();
void reverse();
int append(int num);
void addatbeg(int num);
int addafter(int num, int pos);
void sort();
void delete(int num);

int main()
{
	append(1);
	append(4);
	append(2);
	append(3);
	printf("----Appended list----\n");
	display();
	addatbeg(6);
	addatbeg(7);
	printf("----Addatbeg list----\n");
	display();
	addafter(8, 2);
	addafter(9, 3);
	printf("----Addafter list----\n");
	display();
	sort();
	printf("----sorted list----\n");
	display();
	insert(15);
	insert(5);
	insert(10);
	insert(25);
	insert(20);
	insert(30);
	insert(35);
	insert(40);
	insert(55);
	insert(60);
	insert(50);
	printf("----Ordered list----\n");
	display();
	reverse();
	printf("----Reversed list----\n");
	display();
	delete(55);
	delete(60);
	printf("----After deleted list----\n");
	display();
	return 0;
}

int append(int num)
{
	struct emp *r, *p;
	r = malloc(sizeof(struct emp));
	r->data = num;
	r->next = NULL;
	
	if(h==NULL)
	{
		h = r;
		return;
	}
	for(p=h ; p->next != NULL ; p=p->next);
	p->next = r;
	return;
}

void addatbeg(int num)
{
	struct emp *r;
	r = malloc(sizeof(struct emp));
	r->data = num;
	r->next = h;
	h = r;
}

int addafter(int num, int pos)
{
	int i=1;
	struct emp *r, *p=h;
	r = malloc(sizeof(struct emp));
	r->data = num;
	for( ; i<pos ; i++)
	{
		p=p->next;
		if(p == NULL)
		{
			printf("position > number of elements in a list\n");
			return;
		}
	}
	r->next = p->next;
	p->next = r;
}

void sort()
{
	int temp = 0;
	struct emp *p, *q;
	for(p=h ; p!= NULL ; p=p->next)
	{
		for(q=p->next ; q != NULL ; q=q->next)
		{
			if(p->data > q->data)
			{
				temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
		}
	}
}

void delete(int num)
{
	struct emp *p, *old;
	if(h == NULL)
		return;
	for(p=h ; p!=NULL ; p=p->next)
	{
		if(p->data == num)
		{
			if(p == h)
			{
				h = p->next;
				free(p);
				return;
			}
			else
			{
				old->next = p->next;
				free(p);
				return;
			}
		}
		else
			old = p;
	}
}

int insert(int num)
{
	struct emp *r, *p;
	r=malloc(sizeof(struct emp));
	r->data = num;
	p = h;

	if(h==NULL || (h->data) >= num)
	{
		r->next = h;
		h = r;
		return;
	}
	
	for( ; p->next != NULL ; p=p->next)
	{
		if(p->data < num && p->next->data > num)
		{
			r->next = p->next;
			p->next = r;
			return;
		}
	}

	if(p->next == NULL)
	{
		r->next = NULL;
		p->next = r;
		return;
	}
}

void reverse()
{
	struct emp *p,*q;
	p = NULL;
	while(h != NULL)
	{
		q = p;
		p = h;
		h = h->next;
		p->next = q;
	}
	h = p;
}
void display()
{
	struct emp *p;
	for(p=h ; p!=NULL ; p=p->next)
		printf("data -> %d\n", p->data);
}
