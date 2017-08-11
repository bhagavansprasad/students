#include <stdio.h>
#include <stdlib.h>
typedef struct ll
{
	int data;
	struct ll *link;

}link_l;

link_l *head = NULL;
	int cnt = 0;


void display()
{

	link_l *c = head;
	while(c != NULL)
	{
		printf(" %d ",c->data);
		c = c->link;
	}
	printf("\n");
}



void add ( int n)
{

	link_l *c = NULL;
	link_l *d = NULL;
		c = malloc(sizeof(link_l));
		c->data = n;
		c->link =NULL;
	if(head == NULL)
	{
		printf("no element\n");
	
		head = c;
		cnt++;
		}
	else
	{   
		d=head;
		while(d->link != NULL)
		{
			d = d->link;
		}

		d->link=c;
	}
}
void swap(int a,int b)
  {
		link_l *c,*d;
		if(head)
		{
		 
		}
  }

void sort()
	{
	 link_l *c =NULL;
	 link_l *d =NULL;
	int temp;
	for(c = head; c!=NULL && c->link!= NULL ;c = c->link)
	   {
		 for(d = c->link ; d!=NULL;d= d->link)
		 {
		 if( c->data > d->data)
		 {
		 	temp = c->data;
			c->data = d->data;
			d->data = temp;
		 }
		 }
	  }
	}
main()
{
	link_l *head = NULL;
	add(5);
	add(15);
	add(2);
	add(8);
	add(9);
	add(6);
	display();
	sort();
	display();
}
