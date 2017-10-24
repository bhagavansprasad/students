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


void insert_begin (int n)
{
	link_l *c = NULL;
		c= malloc(sizeof(link_l));
		c->data = n;
		c-> link = NULL;
		if(head != NULL)
 	{
	
	c-> link= head;
	head = c;
	
	}
}

  void insert_last(int n)
  	
{
	 link_l *c = NULL;
	 c = head;
	
	link_l *temp = malloc(sizeof(link_l));
	temp->data = n;
	temp->link = NULL;


	 while(c -> link != NULL)
	{
		c = c-> link;
	}
		c->link = temp;
}

void delete(int n)
	{
		link_l *temp ,*temp1 ,*c;
		temp = head;
		if(head->data == n)
		{
		head = head->link;
		}
		while(temp -> data != n)
		{
		c = temp;
		temp= temp->link;
		}
			temp1 = c->link;
			c -> link = temp1 ->link;
			free (temp1);
		
	   }

main()
{
	link_l *head = NULL;
	add(5);
	add(8);
	add(9);
	add(6);
	insert_begin(4);
	insert_last(2);
	//insert_middle();
	display();
	delete(5);
	display();
}
