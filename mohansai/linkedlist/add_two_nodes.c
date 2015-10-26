#include "stdio.h"
#include "stdlib.h"
struct add
{
	int val;
	struct add *next;
}; 
struct add *head = NULL;

void pass_to_structure(int n,struct add ***p);
void display(struct add **p);
void split(int a,struct add **p);
void displayhead ();
void combine( struct add **p,struct add **q);
main()
{
	struct add *p=NULL,*q=NULL;
	
	int x=12345;
	int y=56789;

	split(x,&p);
	split(y,&q);

	display(&p);
	display(&q);
	
	combine( &p,&q);

	displayhead();
}

void split(int a,struct add **p)
{
	int sum;
	printf("a-->%d\n\r",a);
	
	while(a!=0)
	{
		sum=a%10;
		a=a/10;
		pass_to_structure(sum,&p);
	}
}

void pass_to_structure(int n,struct add ***p)
{
	struct add *new,*temp=**p;
	int i;
	new=malloc(sizeof(struct add));
	new->val=n;
	new->next=NULL;
	
	if(**p==NULL)
	{
		**p=new;
		//printf("1if the elements in the list--> %d\n\r",new->val);
	}
	else
	{
		new->next=temp;
		**p=new;
		//printf("the elements in the list--> %d\n\r",new->val);
	}
/*	for(temp=**p ; temp!=NULL ; temp=temp->next )
	{
		
		printf("temp->val--> %d\n\r",temp->val);
	}
*/
}

void display(struct add **p)
{
	struct add *temp;
	
	//printf("hi welcome to the list\n\r");
	
	for(temp=*p ;temp!=NULL;temp=temp->next)
	{
		printf("the elements in the linked list %d\n\r",temp->val);
	}
	printf("\n\r");
}

	
void combine( struct add **p,struct add **q)
{
	struct add *temp1 = *p , *temp2 = *q , *temp3 , *new,*old;
	
	new=malloc(sizeof(struct add));
	new->val=(temp1->val+temp2->val);
	new->next=NULL;

	if(head==NULL)
	{
		head=new;
		//printf("add the linked list 1 & 2 and store it in 3  %d\n\r",new->val);
	}
		for(  ; temp1 != NULL && temp2 != NULL ; temp1=temp1->next , temp2=temp2->next)
		{
			new=malloc(sizeof(struct add));
			new->val=(temp1->val + temp2->val);
			new->next=NULL;
			
			//printf("add the linked list 1 & 2 and store it in 3  %d\n\r",new->val);
			
			for( temp3=head ; temp3 != NULL ; old=temp3,temp3=temp3->next);
			old->next=new;
		}
	
}
void displayhead ()
{
	struct add *temp;
	for(temp=head ; temp!=NULL ; temp=temp->next)
	{
		printf("the elements in the linked list %d\n\r",temp->val);
	}
	printf("\n\r");
}

	


