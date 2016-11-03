#include<stdio.h>

struct node
{

	int val;
	struct node *next;

};

struct node *h=NULL;

main()
{

	ordered_insert(25);
	ordered_insert(10);
	ordered_insert(20);
	ordered_insert(40);
	ordered_insert(50);
	ordered_insert(25);

	dump_list();

}

int ordered_insert(int n)
{

	struct node *new,*p,*c;

	new=malloc(sizeof(struct node));

	new->val=n;


	if(h==NULL)
	{

		h=new;
		new->next=NULL;

	}

	else
	{
		
		p=c=h;

		for(  ;c!=NULL;  )
		{

			if(n<(c->val))
			{

				if(c==h)
				{

					new->next=h;

					h=new;

					return 0;

			}

				else
				{

					p->next=new;

					new->next=c;

					return 0;

				}

			}	

			p=c;

			c=c->next;

		 }
		/*	 if(new->next==NULL)
		 {

		 	p->next=new;

			return 0;

		 }	*/

		 if(c==NULL)
		 {

		 	p->next=new;

			return 0;

		 }	

	 } 

}	

int dump_list()
{

	struct node *d;

	d=h;
	
	while(d!=NULL)
	{

		printf("Address:%p\t Val:%d\t Next:%p\n",d,d->val,d->next);

		d=d->next;

	}


}	
