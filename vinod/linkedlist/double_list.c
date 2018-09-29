#include <stdio.h>
#include <stdlib.h>

struct emp
{
	struct emp *prev;
	int data;
	struct emp *next;
}*h=NULL;

void display();
int append(int num);
void addatbeg(int num);
int addafter(int num, int pos);
void sort();
int insert(int num);
void delete(int num);
void reverse();
void delete(int num);
void delete_node(struct emp *p);

int main()
{
	struct emp *p;
	int pos=1;
	append(1);
	append(3);
	append(2);
	printf("---Appended list----\n");
	display();
	addatbeg(4);
	addatbeg(5);
	printf("---Addatbeg list----\n");
	display();
	addafter(7, 3);
	addafter(6, 6);
	printf("----Addafter list----\n");
	display();
	sort();
	printf("----sorted list----\n");
	display();
	insert(0);
	insert(10);
	insert(15);
	insert(12);
	insert(11);
	insert(13);
	printf("----Ordered list----\n");
	display();
	reverse();
	printf("----Reversed list----\n");
	display();
	delete(10);
	delete(15);
	delete(0);
	printf("----After deleted list----\n");
	display();
	for(p=h ; pos<1 && p->next!=NULL ; p=p->next,pos++);
	printf("----> Node position : %d\n", pos);
	delete_node(p);
	printf("----After deleting the given node----\n");
	display();
	return 0;
}

void delete_node(struct emp *p)
{
	if(p == h)
	{
		p->next->prev = NULL;
		h = p->next;
		free(p);
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

int append(int num)
{
	struct emp *r, *p;
	r = malloc(sizeof(struct emp));
	r->data = num;
	r->next = NULL;
	if(h == NULL)
	{
		r->prev = h;
		h=r;
		return;
	}
	for(p=h ; p->next!=NULL ; p=p->next);
	r->prev = p;
	p->next = r;
}

void addatbeg(int num)
{
	struct emp *r;
	r = malloc(sizeof(struct emp));
	r->data = num;
	r->prev = NULL;
	r->next = h;
	h = r;
}

void display()
{
	struct emp *p=h;
	for(p=h ; p!=NULL ; p=p->next)
		printf("data ->%d\n", p->data);
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
			printf("position value is > no of elements listed\n");
			return;
		}
	}
	if(p->next != NULL)
	{
		r->next = p->next;
		r->prev = p;
		p->next->prev = r;
		p->next = r;
	}
	else
	{
		r->next = p->next;
		r->prev = p;
		p->next = r;
	}
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

int insert(int num)
{
	struct emp *r, *p;
	r = malloc(sizeof(struct emp));
	r->data = num;
	p = h;

	if(h==NULL || (h->data) >= num)
	{
		r->prev = NULL;
		r->next = h;
		h = r;
		return;
	}
	
	for( ; p->next != NULL ; p=p->next)
	{
		if(p->data < num && p->next->data > num)
		{
			r->next = p->next;
			r->prev = p;
			p->next->prev = r;
			p->next = r;
			return;
		}
	}

	if(p->next == NULL)
	{
		r->next = NULL;
		r->prev = p;
		p->next = r;
		return;
	}
}

void reverse()
{
	struct emp *p, *q;
	p = NULL;
	while(h != NULL)
	{
		q = p;
		p = h;
		h = h->next;
		if(h != NULL)
			h->prev = p;
		p->next = q;
		p->prev = h;
	}
	h = p;
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
				h->prev = NULL;
				free(p);
				return;
			}
			else
			{
				old->next = p->next;
				if(p->next != NULL)
					p->next->prev = old;
				free(p);
				return;
			}
		}
		else
			old = p;
	}

}
