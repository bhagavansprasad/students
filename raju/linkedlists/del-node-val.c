#include<stdio.h>


struct node
{

	int val;
	struct node *next;

};

struct node *h=NULL;

main()
{

/*	add_node(10);
	add_node(25);
	add_node(20);
	add_node(40);
	add_node(50);*/

	dump_list();

	del_node_val(10);

	printf("After Deleting\n");

	dump_list();


}

int add_node(int n)
{

	struct node *new,*p;

	new=malloc(sizeof(struct node));

	new->val=n;
	new->next=NULL;

	if(h==NULL)
	{
		h=new;
	}

	else
	{
		p=h;

		for(  ;(p->next)!=NULL;  )
		{
			p=p->next;
		}	

		p->next=new;

//		return 0;

	}

}	

int dump_list()
{

	struct node *d;

	d=h;

	if(d==NULL)
	{
		
		printf("No nodes are present\n");

	}	
	
	while(d!=NULL)
	{

		printf("Address:%p\t Val:%d\t Next:%p\n",d,d->val,d->next);

		d=d->next;

	}


}


int del_node_val(int value)
{

	struct node *c,*p;

	p=c=h;

	if(h==NULL)
	{
		
		printf("No nodes are there to delete\n");

	}	


	while(c!=NULL)
	{
		

		if(c->val==value)
		{
			
			if(c==p)
			{

				h=p=c->next;

				free(c);

				return 0;
			}

			else
			{

				p->next=c->next;

				free(c);

				return 0;

			}

		}	

		p=c;

		c=c->next;	

	}

}	
