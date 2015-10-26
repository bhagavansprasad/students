#include <stdio.h>
#include <stdlib.h>

void display();
int append(int num);
void addatbeg(int num);
int addafter(int num,int pos);
void sort();
int insert(int num);
void delete(int num);
void reverse();
void delete(int num);

struct emp
{
	struct emp *prev;
	int data;
	struct emp *next;
}*h = NULL;


void delete_node(struct emp *p)
{
	p -> prev -> next = p -> next;
	p -> next -> prev = p -> prev;
	free(p);
}

int append(int num)
{
	struct emp *r , *p;
	r = malloc(sizeof (struct emp));
	r -> data = num;
	r -> next = NULL;
	if(h == NULL)
	{
		r -> prev = h;
		h = r;
		return ;
	}
	for(p = h ; p->next!=NULL ; p=p->next);
	r -> prev = p;
	p -> next = r;
}

void addatbeg(int num)
{
	struct emp *r;
	r = malloc(sizeof (struct emp));
	r -> data = num;
	r -> prev = NULL;
	r ->next = h;
	h=r;
}

void display()
{
	struct emp *p = h;
	for(p=h;p!=NULL;p=p->next)
	printf("data %4d\n ",p->data);
}

int main()
{
	struct emp *p;
	int pos = 1;
	append(1);
	append(3);
	append(2);
	printf("----> appended list<----\n");
	display();
	addatbeg(4);
	addatbeg(5);
	printf("---->addatbeg list<----\n");
	display();
	for(p=h ; pos<4 && p->next != NULL ;p=p->next,pos++);
	printf("---->Node position : %d\n",pos);
	delete_node(p);
	printf("---->after deleting the given node<----\n");
	display();
	return 0;
}
