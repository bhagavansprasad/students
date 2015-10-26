#include"stdio.h"
#include"stdlib.h"

struct node
{
  int data;
  struct node *next;
};

struct node *h=NULL;




int add_anode(int val)
{
  struct node *new,*temp;
  new=malloc(sizeof(struct node));
  new->data=val;
  new->next=NULL;
  if(h==NULL)
  {
    h=new;
    return 0;
  }
  for(temp=h;temp->next!=NULL;temp=temp->next);
  
  temp->next=new;
  
  return 0;
}






void display()
{
  struct node *temp;
  for(temp=h;temp!=NULL;temp=temp->next)
  {
    printf("%d",temp->data);
  }
}






int main()
{
  add_anode(10);
  add_anode(20);
  //add_anode(30);
  display();
  return 0;
}



