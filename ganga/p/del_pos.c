#include <stdio.h>
#include <stdlib.h>
int addnode(int);
int display(void);
int del_pos(int);
struct node
{
	int value;
	struct node *next;
	struct node *c;
};
struct node *h=NULL;
int main()
{
	addnode(10);
	addnode(90);
	addnode(20);
	addnode(40);
	addnode(60);
 	display();
	del_pos(2);
	display();

}

int addnode(int n)
{
	struct node *temp=NULL;
	struct node *ptr=NULL;
	ptr=malloc(sizeof(struct node));
	ptr->value=n;
	ptr->next=NULL;
	ptr->c=NULL;
	if(h==NULL)
	{
		h=ptr;
		temp=h;
		return 0;
	}
	for(temp=h;temp->next!=NULL;temp=temp->next)
	{
	}
	temp->next=ptr;
	ptr->c=temp;

	return 0;
}
int del_pos(int a)
{
    struct node *temp=NULL;
	struct node *ptr=NULL;
	for(i=0;temp->next!=NULL;


}
int display(void)
{
	struct node *temp=NULL;
	temp=h;
	while(temp!=NULL)
	{
		printf("v=%d\t ",temp->value);
		printf("n=%u\t",temp->next);
		printf("c=%u\n",temp->c);
		temp=temp->next;
	}
	printf("\n");
	return 0;	
}

