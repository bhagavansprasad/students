#include<stdio.h>
#include <string.h>
typedef struct node_t
{
	char *p;
	struct node_t *next;
}node;
node *head=NULL;
char *p[5]={"manohar","reddy","challa","naga","indra"};
main()
{
	int i=0;
	display();
	for(i=0;i<=4;i++)
	{
		add_node(p[i]);
	}
	display();

}
int add_node(char *m)
{	
	node *temp=NULL;
	node *new=malloc(sizeof(struct node_t));
	new->p=m;
	if(head == NULL)
	{
		head=new;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);

		temp->next=new;

	}
	return 0;
}
int display()
{
	node *temp=NULL;
	for(temp=head;temp!=NULL ;temp=temp->next)
		printf("%s\n",temp->p);
	return 0;
}





