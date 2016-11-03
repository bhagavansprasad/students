#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *next;
};
struct node *head[2] = {NULL};
struct node *start=NULL;
/*function for creating two link lists*/
main()
{
	int t,sum=0,c=0;
	int a=1234;
	int b=4567;
	add_num_list(a,0);
	add_num_list(b,1);
	display(head[0]);
	printf("\n");
	display(head[1]);
	printf("\n");
	while(head[0]!=NULL)
  {
	t=head[0]->val+head[1]->val+c;
	sum=t%10;
	add_two_node(sum);
	c=t/10;
	head[0]=head[0]->next;
	head[1]=head[1]->next;
  }
  printf("%d",c);
  display(start);
  printf("\n");
  exit(1);
}
int	add_two_node(int n)
{
	struct node *new,*temp=start;
	new = malloc(sizeof(struct node));
	new->val = n;
	new->next=NULL;
	if(start == NULL)
	{
		start = new;
		return 0;
	}
	new->next = start;
	start = new;
	return 0;
}
int add_num_list(int val,int index)
{
	while(val!=0)
	{
	 adding_node(val%10,index);
	 val=val/10;
	}
}
int  adding_node(int n,int index)
{
	int h1=index;
	struct node *new,*temp = head[h1];
	new = malloc(sizeof(struct node));
	new -> val = n;
	new -> next = NULL;
	if(head[h1] == NULL)
	{
		head[h1] = new;
		return 0;
	}
	while( temp -> next != NULL)
	temp = temp -> next;
	temp ->next = new;
	return 0;
}
int display(struct node *head)
{
	struct node *t;
	for(t=head;t!=NULL;t=t->next)
	{
		printf("%5d ",t->val);
	}
	return 0;
}
