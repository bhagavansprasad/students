#include <stdio.h>
#include <stdlib.h>
int addnode(int);
int display(void);
//int del_pos(int);
struct node
{
	int value;
	struct node *next;
};
struct node *h=NULL;
int j;
int main()
{
	addnode(10);
	addnode(90);
	addnode(20);
	addnode(40);
	addnode(60);
 	display();
//qdisplay();
//	del_pos(6);
//	del_pos(1);
//	display();
//	get_node_count();
//	del_pos(2);
//	display();

}

int addnode(int n)
{
	struct node *temp=NULL;
	struct node *ptr=NULL;
	ptr=malloc(sizeof(struct node));
	ptr->value=n;
	ptr->next=h;
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

	return 0;
}
int display(void)
{
	struct node *temp=NULL;
	temp=h;
	while(temp->next!=h)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}
	printf("\n");
	return 0;	
}
/*int del_pos(int p)
{
	struct node *temp=NULL;
	struct node *ptr=NULL;
	int a,i=1;
	temp=h;
		get_node_count();
		printf("%d\n",j);
		if(p>j)
		{
		printf("not possible");
		return 0;
		}

	while(temp!=NULL)
	{
		if(p==1)
		{
			h=temp->next;
			free(temp);
			return 0;
		}
		if(p==i)
		{
			ptr->next=temp->next;
			free(temp);
			return 0;
		}
		i++;
		ptr=temp;
		temp=temp->next;


	}
//	printf("not possible");
}*/

