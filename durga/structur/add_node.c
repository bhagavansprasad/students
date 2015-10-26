#include <stdio.h>
#include <stdlib.h>
int addd_node(int );
struct node
{
	int val;
	struct node *link;
};
struct node *head[2] = {NULL,NULL};
struct node *start = NULL;
/*function for creating two link lists*/
int addd_node(int n)
{
	int h1;
	struct node *new,*t;
	new=malloc(sizeof(struct node));
	new->val = n;
	new->link=NULL;
	h1 = get_key(n);
	if(head[h1]==NULL)
	{
		head[h1]=new;
		return 0;
	}
	// for(t=head[h1];t->link!=NULL;t=t->link);
	//t->link=new;
	new->link = head[h1];
	head[h1] = new;
	return 0;
}

/*function for result node creationt*/

int adding_node(int n)
{

	struct node *new,*temp = start;
	new=malloc(sizeof(struct node));
	new->val = n;
	new->link=NULL;
	if(start == NULL)
	{
		start = new;
		return 0;
	}
	// for(t=head[h1];t->link!=NULL;t=t->link);
	//t->link=new;
	new->link = start;
	start = new;
	return 0;
}

/*function for display*/

int display(struct node *head)
{
	struct node *t;
	for(t=head;t!=NULL;t=t->link)
	{
		printf("%d\n",t->val);
	}
	return 0;
}
/*function for get_key*/

int get_key(int size)
{
	if(size<=5)
		return 0;
	if(size>5 && size <= 9)
		return 1;
}
/*function for adding two linked list*/

/*int adding_link( struct node *list)
{
	 struct node *first = list;
	struct node *second = list+1;
	int t,sum = 0, c = 0;
	while( first != NULL)
	{
		t = first ->val + second->val + c;
		sum = t %10;
		adding_node(sum);
		printf("%d\n",sum);
		c = t/10;
		first = first ->link;
		second = second ->link;
		return 0;
	}
}*/
main()
{
int t, sum = 0, c = 0;
	addd_node(2);
	addd_node(4);
	addd_node(3);
	addd_node(6);
	addd_node(9);
	addd_node(7);
	display(head[0]);
	printf("\n");
	display(head[1]);
  while(head[0]!= NULL)
  {
   t = head[0] ->val + head[1] ->val + c;
   sum = t %10;
   adding_node(sum);
   c = t/10;
   head[0] = head[0] ->link;
   head[1] = head[1] ->link;

   }
   printf("\n");
  display(start);
}

