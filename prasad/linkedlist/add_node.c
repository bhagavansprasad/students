#include"stdio.h"
#include"stdlib.h"

struct node
{
	int val;
	struct node *next;
};
struct node *h=NULL;
int add_anode(int val)
{
	struct node *ptr,*temp;
	ptr=malloc(sizeof(struct node));
	ptr->val=val;
	ptr->next=NULL;
	if(h==NULL)
	{
		h=ptr;
		return 0;
	}
	for(temp=h;temp->next!=NULL;temp=temp->next);
	{
	}
	temp->next=ptr;

	return 0;
}
void display()
{
	struct node *temp;
	for(temp=h;temp!=NULL;temp=temp->next)
	{
		printf("%d\n",temp->val);
	}
}
int main()
{
	add_anode(10);
	add_anode(20);
	add_anode(30);
	display();
	return 0;
}




