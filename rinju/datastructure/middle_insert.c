#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	int data;
	struct ll *link;

}link_l;
link_l *head = NULL;
int cnt =0;
void insert(int n)
{
	link_l *d =NULL;
	link_l *c = NULL;

	c = malloc(sizeof(link_l));
	c->data = n;
	c->link = NULL;
	if(head == NULL)
	{
		head = c;

	}

	else
	{
		d = head;
		while(d->link != NULL)
		{
			d = d-> link;
		}
		d-> link = c;
	}
	cnt++;
}

void search(int n)
{
	link_l *c =head;
	while(head != NULL && c->data != n)
	{
		c=c->link;
	}
	printf(" search=%d ",c->data);
}

void display()
{
	link_l *c = head;
	while(c!=NULL)
	{
		printf(" %d ",c->data);
		c=c->link;

	}

	printf("\n");
}

main()
{
	insert(2);
	insert(9);
	insert(4);
	insert(5);
	//	st_delete();
	display();
	search(9);
	printf(" cnt = %d ",cnt);
}
