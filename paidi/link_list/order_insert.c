#include<stdio.h>
#include<stdlib.h>
int add(int);
void display();
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head=NULL;

main()
{

	add(60);
	display();
	add(30);
	display();
	add(40);
	display();
	add(10);
	display();
	add(15);
	display();

}

int add (int x)
{
	node *temp,*new,*old;
        printf("enter %s\n %d\n",__FUNCTION__,__LINE__,x);
	new=malloc(sizeof(node));
	new->data=x;
	new->next=NULL;
		if(head==NULL)
		{
			head=new;
		       	return 0;
		}

	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data>=x)
		{
			if(temp==head)
			{
				new->next=head;
				head=new;
				return 0;
			}
			else
			{
				new->next=temp;
				old->next=new;
			     	return 0;
			}
		}
		else
			old=temp;
	
        }	
        
	old->next=new;
        return 0;
        

}
 void display()
{
	node *temp;	
	temp=head;

	printf("-->%s\n", __FUNCTION__);

	while(temp!=NULL)
	{
		printf("%4d",temp->data);
		temp=temp->next;	 
	}

	printf("\n");

}


