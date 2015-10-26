#include<stdio.h>
struct data_t
{
	int value;
	struct data_t *p;
}node;
struct data_t *h=NULL;
main()
{
	add(10);
	add(20);
	display();
	delete(10);
	display();
	delete(20);
}
int add(int a)
{
	node *t;
	node *temp=NULL;
	t=malloc(sizeof(struct node));
	t->value=a;
	t->p=NULL;
	if(h==NULL)
	{
		h=t;
		return 0;
	}
	while(temp->p!=NULL)
		temp=temp->p;
	temp->p=t;
	return 0;
}
void display(void)
{
	struct node *temp;
	for(temp=h;temp!=NULL;)
	{
		printf(("%d\t",temp->value);
		temp=temp->p;
	}	
}
				int delete(int value)
				{
				struct node *temp;
				struct node *i;
				struct *a;
				i=h;
				if(i==NULL)
				{
				printf("\n this is empty list..\n");
				return(0);
				}
				if(i->n==value)
				{
				temp=i->p;
				a=i->p;
				h=temp;
				//	printf("%d is deleted which is first node\n",value);
				//if(h==NULL)
				//printf("empty list");
				free(a);
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
