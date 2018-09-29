#include<stdio.h> 
#include<stdlib.h>

struct node
{
	int no;
	struct node *N;
};

struct node *h = NULL;

int add_node(int value);
int search_node(int value);
int val = 40,d =0;
void display();

int main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_node(60);
	d = search_node(40);
	printf("%d is available in %d rd node \n",val,d);
	//delete_node(10);
	//delete_node(40);
	//delete_node(60);
	display();
}
void display()
{
	struct node *t;
	for(t=h;t!=NULL;t=t->N)
	{
		printf("%d\n",t->no);
	}
}

int add_node(int value)
{
	struct node *new,*t;
	new = malloc(sizeof(struct node));
	new->no = value;
	new->N  = NULL;

	if(h == NULL)
	{
		h = new;
		return 0;
	}

	for(t = h; t->N!= NULL;t=t->N);
	t->N = new;
	return 0;
}

/*int delete_node(int value)
  {
  struct node *curr,*pre;
  for(curr=h;curr!=NULL;pre=curr,curr=curr->N)
  {
  if(curr->no==value)
  {
  if(curr==h)
  {
  h=curr->N;
  }
else 
  pre->N=curr->N;
  free(curr);
  }
  }
  return 0;
  }*/
int search_node(int value)
{
	struct node *t;
	int c=1;
	for(t=h;t!=NULL;t=t->N)
	{
		if(t->no==value)
		{
			return c;
		}
		c++;
	}

}
