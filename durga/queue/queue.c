
#include <stdio.h>
#include <stdlib.h>
void display(void);
int pop(void);
int push(int );

struct node
{
	int val;
	struct node *link;
};
struct node* head = NULL;

main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	display();
	pop();
	pop();
	pop();
	printf("\n");
	display();
}
/*function for push()*/
int push(int data)
{
	struct node *temp,*new;
	temp = head;
	new = (struct node*) malloc(sizeof(struct node));
	new ->val = data;
	new ->link = NULL;
	if(head == NULL)
	{
		head = new;
		return 0;
	}
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = new;
	return 0;
	
}


/*function for displauy*/
void display()
{
	struct node* temp = head;
	while(temp != NULL)
	{
		printf("%d\n",temp->val);
		temp = temp->link;
	}
}




/*function for pop()*/


int pop (void)
{
	struct node* temp;
	temp = head;
	if(head->link == NULL)
	{
	printf("stack  is empty\n");
	head = NULL;
		free(temp);
		return 0;
	}
	head = temp->link;
	free(temp);
	return 0;
}
