#include<stdio.h>


struct node
{

	int val;
	struct node *next;
	struct node *prev;

};

struct node *h=NULL;

main()
{

	add_node(10);
	add_node(25);
	add_node(20);
	add_node(40);
	add_node(50);

	dump_list();

	insert_node_after(3,90);

	printf("After Adding\n");

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
		return 0;
	}

	else
	{
		p=h;

		for(  ;(p->next)!=NULL;  )
		{
			p=p->next;
		}	

		p->next=new;
		new->prev=p;

//		return 0;

	}

}	

int dump_list()
{

	struct node *d;

	d=h;

	if(h==NULL)
	{

		printf("No Nodes are present\n");

	}	
	
	while(d!=NULL)
	{

		printf("Prev:%p\t Address:%p\t Val:%d\t Next:%p\n",d->prev,d,d->val,d->next);

		d=d->next;

	}


}


int insert_node_after(int pos,int value)
{

	struct node *c,*new;
	int i;

	c=h;


	for(i=1;c!=NULL;i++)
	{
		

		if(pos==i)
		{


			new=malloc(sizeof(struct node));

			new->val=value;
			new->next=c->next;
			new->prev=c;

			c->next->prev=new;
			c->next=new;

			return 0;

		}	

		c=c->next;	

	}

	if(h==NULL)
	{

		printf("No Nodes are there\n");

	}	



}	
