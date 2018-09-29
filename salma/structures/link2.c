# include<stdio.h>
#include <stdlib.h>
int add( int );
void display(void);
int add_first(int );
int add_last(int );
int add_middle(int ,int );
int delete(int);

struct node 
{
	int n;
	struct node *p;	
};
struct node *t;
struct node *h = NULL;
main()
{
	//	struct node *d;
	add(10);
    add(20);
	add(30);
	add(40);
	display();
/*	add_first(5);
	display();
	add_last(50);
	display();
	add_middle(25,2);
	display();
	delete(50);
	display();
	delete(5);
	display();*/
	delete(30);
	display();

}


int add( int num)
{
	struct node *temp = h;
	t = malloc(sizeof(struct node));
	t -> n = num;
	t -> p = NULL;
	if( h == NULL)
	{
		h = t;
		return 0;
	}
	while (temp ->p != NULL)
	{
		temp = temp ->p;
	}
	temp ->p = t;
	return 0 ;
}

void display(void)
{
	struct node *temp;
	for(temp=h;temp!=NULL;temp=temp->p)
	{
		printf("%d\n",temp->n);
	}
	printf("\n this is next display\n");
}
int add_first(int newroll)
{
	struct node *new;
	new=malloc(sizeof(struct node));
	new->n=newroll;
	new->p=h;
	h=new;
	printf("%d is added at first here\n",newroll);
	return(0);
}
int add_last(int lastroll)
{

	struct node *last;
	last=malloc(sizeof(struct node));
	last->n=lastroll;
	last->p=NULL;
	//t->p=last->p;
	t->p=last;
    printf("%d is added at last here \n",lastroll);
    return(0);
}
int add_middle(int value,int postion)
{
	struct node *insert;
	struct node *i;
	int c=0;
	for(i=h;i->p!=NULL;i=i->p)
	{
		c++;
		if(c==postion)
		{
			insert= malloc(sizeof(struct node));
			insert->n=value;
			insert->p=i->p;
			i->p=insert;
           printf("%d is added in middle  here\n",value);
 
		}
	}
}
int delete(int value)
{
	struct node *temp;
	struct node *i;
	i=h;
	if(i==NULL)
	{
		printf("\n this is empty list..\n");
		return(0);
	}
	if(i->n==value)
	{
		temp=i->p;
		h=temp;
	//	printf("%d is deleted which is first node\n",value);
		//if(h==NULL)
		//printf("empty list");
		return(0);
	}
	for(;i->p!=NULL;i=i->p)

	{
		if(i->p->n == value )
		{
			temp=i->p;
			i->p=temp->p;
			printf("%d is delete here which is a middle node\n",value);
			return(0);
		}
	}
}
