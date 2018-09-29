#include"stdio.h"
#include"stdlib.h"

typedef struct node_t
{
	int data;
	struct node_t *next;
}node;
node *head=NULL;

int addnode(int n);
void display();
void add_node_starting(int n);
int modify(int x,int y);
int delete(int n);
int loop( );
int count_node();
int get_middle_element(void);
void addend(int);
void addpos(int,int);
int addnode(int n)
{
	node *new=NULL,*temp=NULL;
	new=malloc(sizeof(node));
	new->data=n;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		return 0;
	}
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
	return 0;
}

void display()
{
	node *temp=NULL;
	temp=head;
	printf("the elements are\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

int count_node()
{
	node *temp;
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	printf("Number of nodes in the Linked list are %d\n",count);
	return 0;

}

void add_node_starting(int n)
{
	node *new=NULL;
	new=malloc(sizeof(node));
	new->data=n;
	new->next=head;
	head=new;

	printf("After adding of node at begin ");
}
void addend(int n)
{
	//	printf("its a add at the end result\n");
	node *temp,*new;

	printf("-->%s :%d\n", __FUNCTION__, n);

	for(temp=head;temp->next!=NULL;temp=temp->next);
	new=malloc(sizeof( node));
	new->data=n;
	temp->next=new;
	new->next=NULL;

}

int modify(int x,int y)
{
	node *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			temp->data=y;
			return y;
		}
		else
			temp=temp->next;
	}
	printf("list doesnot contain %d value\n",x);

	printf("After Modification ");
	return 0;
}

int delete(int n)
{
	printf("After Deletion");
	node *temp=NULL,*old=NULL;

	temp=head;

	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			if(temp==head)
			{
				head=temp->next;
				free(temp);
				return 0;
			}
			else
			{
				old->next=temp->next;
				free(temp);
				return 0; 
			}
		}
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
	printf("the list doesnot contain the element you want to delete\n");


	return 0;
}


int loop( )
{
	node *temp1=NULL;
	node *temp2=NULL;
	temp1=head;
	temp2=head;
	while(temp1->next!=NULL && temp2!=NULL)
	{
		if(temp1 == temp2)
		{
			printf("loop detected \n");
          //printf(" between The addresses   %d %u\t %d %u\t\n",temp1,temp2,temp1->data,temp2->data);
			return 0;
		}
		temp1=temp1->next;
		if(temp2->next != NULL)
			temp2=temp2->next->next;
		else
			temp2=temp2->next;
	}
	printf("no loop detected\n");

	return 0;
}


int Reverse_linked_list()
{
	node *prev=NULL,*temp=NULL;
	while(head!=NULL)
	{
		temp=head;
		head=temp->next;
		temp->next=prev;
		prev=temp;
	}
	head=temp;
	return 0;
}

int get_middle_element(void)
{
	node *temp1,*temp2;
	temp1 = head;
	temp2 = head;
	while(temp2 != NULL && temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	printf("Middle Node data is: %d\n",temp1->data);

	return 0;
}
void addpos(int n,int pos)
{
	//printf("its a add at the middle\n");

	node *temp,*new;
	int i;

	printf("-->%s n :%d, pos :%d\n", __FUNCTION__, n, pos);

	temp=head;
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
		if(temp->next == NULL)
		{
			printf("there are less than nodes=%d\n ",pos);
                        exit(0);

		}
	}
	new=malloc(sizeof( node));
	new->data=n;
	new->next=temp->next;
	temp->next=new;
}

int main()
{
	addnode(10);
	addnode(20);
	addnode(30);
	addnode(31);
	addnode(35);
	addnode(98);
    addnode(40);
	addnode(50);
	addnode(80);
	display();
	Reverse_linked_list();
	display();


}
	
