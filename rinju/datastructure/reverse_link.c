#include<stdio.h>
#include<stdlib.h>
	typedef struct ll
		{
		int data;
		struct ll *link;

		}link_l;
   link_l *head = NULL;
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
			}
	void reverse_list()
	 {
	   link_l *prev = NULL;
	   link_l *curr = head;
	   link_l *next ;
	   while(curr != NULL)
	    {
		 next = curr-> link;
		 curr->link = prev;
		 prev = curr;
		 curr = next;
		}
		head = prev;
	 }
	 void reverse(link_l *head)
	 {
	  //link_l *c;
	  //c = head;
	  if(head == NULL)
	   return;
	   reverse(head->link);
	   printf(" %d ",head->data);
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
			//swap();
			display();
			reverse_list();
			display();
			reverse(head);
			}
