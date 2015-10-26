# include<stdio.h>
#include <stdlib.h>
int add( int );
void display(void);
int add_first(int );
int add_last(int );
int add_middle(int ,int );
void deletefirst(void);
void deletelast(void);
int deletemiddle(int);
 int add_middle1after(int,int);
 //int add_middlebefore(int,int);
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
	add_first(5);
	display();
	add_last(50);
	display();
		add_middle(25,2);
	display();
    deletefirst();
	display();
	deletelast();
	display();
	deletemiddle(3);
	display();
	add_middle1after(30,35);
	display();
//	add_middlebefore(55,40);
//	display();
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
	printf("this is add at first\n");
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
		printf("this is add at last\n");
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
				printf("this is add at middle\n");

		}
	}
}
void deletefirst(void)
{
h=h->p;
	printf("this is delete at first\n");

}
void deletelast(void)
{
struct node *i;
struct node *temp;
for(i=h;i->p!=NULL;i=i->p)
temp=i;
temp->p=NULL;
	printf("this is delete at last\n");
}
int deletemiddle(int postion)
{
struct node *temp;
struct node *i;
int c=0;
for(i=h;i->p!=NULL;i=i->p)
{
c++;
if(c==postion)
{
i=i->p->p;
printf("delete at middle\n");
}
}
}
int add_middle1after(int cmpvalue,int newvalue)
{
	struct node *insert;
	struct node *i;
	int c=0;
	for(i=h;i->p!=NULL;i=i->p)
	{
		if(cmpvalue==i->n)
		{
			insert= malloc(sizeof(struct node));
			insert->n=newvalue;
			insert->p=i->p;
			i->p=insert;
				printf("this is add in middle by value after node\n");

		}
	}
}
/*int add_middle1before(int cmpvalue1,int newvalue1)
{
struct node *next;
struct node *temp;
struct node *new;
for(temp=h;next=temp->p;next->p!=NULL);
temp=temp->p;
next=next->p;
if(next->n==cmpvalue1)
{
new=malloc(sizeof(struct node));
new->n=newvalue1;
new->p=next;
temp->p=new;
printf("this add before node\n");
}
return(0);
}*/
