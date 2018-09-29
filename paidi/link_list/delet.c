#include<stdlib.h>
#include<stdio.h>
/*proto type*/
void delete(int);
void add(int);
void display();
void count();
void addfirst(int);
void addend(int);
void addpos(int,int);
void orderd_inset(int,int,int,int);
		
typedef struct node
{
	int data;
	struct node *next;
}node;
      node *head=NULL;

main()
{
	display();
	delete(50);
	delete(50);
	delete(50);
	delete(50);
	display();
	add(20);
	display();
	add(30);
	display();
	add(40);
	display();
	add(50);
	display();
	add(60);
	display();
	delete(30);
	display();
	delete(50);
	display();
	count();
	display();
	addfirst(80);
	display();
	display();
	addend(100);
	display();
	delete(100);
	display();
	delete(80);
	display();
	addpos(202,2);
	display();
	count();
	display();

}	

void add (int x)
{
	node *new,*temp;
	new=malloc(sizeof( node));

	printf("-->%s %d, :%d\n", __FUNCTION__, __LINE__, x);

	new->data=x;
	new->next=NULL;

	if(head==NULL)
	{
		head=new;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=new;
	}
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


void delete(int x)
{
	node *temp,*old;
	temp=head;

	printf("-->%s :%d\n", __FUNCTION__, x);

	while(temp!=NULL)
	{
		if(temp->data== x)
		{
			if(temp==head)
			{
			       //head=NULL;
				//free(temp);
                              head=temp->next;
                               free(temp);
			}
			else
			{
				old->next=temp->next;
				free(temp);
			}
		}
		else
		{
			old=temp;
			temp=temp->next;
		}
	}
}
void count()
{
	int c=0;
	node *temp;

	printf("-->%s\n", __FUNCTION__);

	temp = head;
	while(temp!=NULL)
	{
		c++;
		temp = temp->next;
	}
	printf("nodes count--------->=%d",c);
	printf("\n");
}

void addfirst(int n)
{
	//	printf("its a add at the begenning result\n");
	node *temp,*new;

	printf("-->%s :%d\n", __FUNCTION__, n);

	temp=head;
	new=malloc(sizeof( node));
	new->data=n;
	new->next=temp;
	head=new;

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


