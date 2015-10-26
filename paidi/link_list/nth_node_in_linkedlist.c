#include<stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
int addnode(int a)
{
	struct node *temp,*new;
	new = malloc(sizeof(struct node));
	new->data =a;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		return 0;
	}
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=new;
}

void n_th_node ()
{
	struct node *temp1=head,*temp2;
	int count = 0;
	while(temp1!=NULL)
	{
		printf("%d\t",temp1->data);
		temp1=temp1->next;
		count++;
		if(count==5)
		{
			temp2 = head;
		}
		else if(count>5)
		{
			temp2 = temp2->next;
		}
	}
	if(count<5)
		printf("\n n-5th node not available in list \n");
	else
		printf(" \n n-5th node is :%d\n",temp2->data);
	printf("\n");
}


int main()
{
  
addnode(10);
addnode(20);
addnode(30);
addnode(40);
addnode(50);
addnode(60);
addnode(70);
addnode(80);
addnode(90);
addnode(100);
n_th_node ();
}
