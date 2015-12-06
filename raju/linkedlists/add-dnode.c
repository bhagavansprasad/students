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
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);

	dump_list();

	add_node_beg(90);
	add_node_beg(80);

	printf("After adding\n");

	dump_list();

}

int add_node(int n)
{

	struct node *new,*p;

	new=malloc(sizeof(struct node));

	new->val=n;
	new->next=new->prev=NULL;


	if(h==NULL)
	{
		h=new;
		return 0;
	}

	else
	{
		

		for(p=h  ;(p->next)!=NULL;  )
		{
			p=p->next;
		}	

		p->next=new;

		new->prev=p;



//		return 0;

	}

}

int add_node_beg(int n)
{

	
	struct node *new,*p;

	p=h;

	new=malloc(sizeof(struct node));

	new->val=n;
	new->next=h;
	new->prev=NULL;


	if(h==NULL)
	{
	
		h=new;
		return 0;
			
	}
	else
	{

		h->prev=new;
		h=new;
		return 0;

	}	

}	




int dump_list()
{

	struct node *d;

	d=h;
	
	while(d!=NULL)
	{

		printf("Prev:%p\t Address:%p\t Val:%d\t Next:%p\n",d->prev,d,d->val,d->next);

		d=d->next;

	}


}	
