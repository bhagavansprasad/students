#include <stdio.h>
#include <malloc.h>
typedef struct node_t
{
	int val;
	struct node_t *next;
}node;
node *head = NULL;

int addnode(int n)
{
	node *temp = NULL, *new = NULL;
	new = malloc(sizeof(node));
	new->val = n;
	new->next = NULL;

	if(head == NULL)
	{
		head = new;
		return 0;
	}
	for(temp = head ; temp->next != NULL; temp = temp->next);
	temp->next = new;
	return 0;
}

void display()
{
	node *temp = NULL;
	for(temp =head ;temp!= NULL ;temp=temp->next)
	{
		printf("The node val is:%d\n",temp->val);
	}
}

void middlenode()
{
	node *temp1=NULL, *temp2=NULL,*prev=NULL;
	temp1 = temp2 = head;
	while(temp2 != NULL && temp2->next != NULL)
	{
		prev = temp1;
		temp1=temp1->next;
		temp2=temp2->next->next;
	}
	printf("--------------->the middle node is %d\n",temp1->val);

	prev->next = temp1->next;
	free(temp1);
	return ;	
}



int main()
{
	addnode(10);
	addnode(12);
	addnode(110);
	addnode(115);
	addnode(120);
	addnode(1);
	addnode(102);
	addnode(140);
	addnode(100);
	display();
	middlenode();
	display();
}
