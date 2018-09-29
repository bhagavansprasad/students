#include"stdio.h"
#include"stdlib.h"

struct node
{
  int data;
  struct node *next;
};

struct node *h=NULL;

int add_anode(int pos ,int val)
{
  struct node *temp,*prev;
  int flag=1,i;
  struct node *new=malloc(sizeof(struct node));
  new->data=val;
  new->next=NULL;
  if(h==NULL)
  {
    h=new;
    return 0;
  }
  if(h->next==NULL)
  {
    if(flag==pos)
    {
      new->next=h;
      h=new;
      return 0;
    }
    else 
      h->next=new;
    return 0;
  }
  for(i=1,prev=temp=h;temp->next!=NULL;prev=temp,temp=temp->next,i++)
  {
    if(i==pos)
    {
      temp=temp->next;
      prev->next=new;
      new->next=temp;
      return 0;
    }
  }
  temp->next=new;
  return 0;
}

void display()
{
  struct node *temp;
  for(temp=h;temp!=NULL;temp=temp->next)
    printf("%d \t",temp->data);
  
}


int main()
{
  add_anode(1,10);
  add_anode(2,20);
  add_anode(3,30);
 add_anode(4,40);
  add_anode(2,70);
  add_anode(1,80);
  display();
return 0;
}
int del_by_val(int val)
{
	struct node *prev =  NULL, *curr = h;

	if(h->no == val)
	{
		h = curr->N;
		free(curr);
		return 0;
	}

	while(curr != NULL)
	{	
		if(curr->no == val)
		{
			prev->N = curr->N;
			free(curr);

			return 0;
		}
		prev = curr;
		curr = curr->N;
	}
	if(curr == NULL)
	{
		prev = NULL;
		free(curr);
		return 0;
	}
	return 0;
}
