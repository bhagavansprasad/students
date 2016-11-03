#include<stdio.h>
#include <stdlib.h>
void display(void);
int push(int );
int pop(void);

struct node
{
	int val;
	struct node* link;
};
struct node* head = NULL;

main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	display();
	printf("\n");
	pop();
	pop();
	pop();
	display();
}

/*function for push()*/

int push(int data)
{
	struct node *temp;
	struct node *new;
	temp = head;
	new = (struct node*)malloc(sizeof(struct node) );
	new->val = data;
	//new->link = NULL;
	if(head == NULL)
	{
		head = new;
		new->link = NULL;
		return 0;
	}
	new ->link = head;
	head = new;
	return 0;
}

/*function for display()*/

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
		head = NULL;
		free(temp);
		return 0;
	}
	head = temp->link;
	free(temp);
	return 0;
}
