#include"stdio.h"
#include"stdlib.h"

struct node
{
int d;
struct node *next,*prev;
};

struct node *h=NULL;

int add_double(int val)
{
struct node *temp;
struct node *new=malloc(sizeof(struct node));
new->d=val;
new->next=new->prev=NULL;
if(h==NULL)
{
h=new;
return 0;
}
for(temp=h;temp->next!=NULL;temp=temp->next);
temp->next=new;
new->prev=temp;
return 0;
}

int  delete(int val)
{
struct node *temp,*cur;
if(h==NULL)
{
printf("THERE IS NO NODE TO DELETE THE ELMENT");
return 1;
}
else if(h->next==NULL)
{
h=h->next;
h->prev=NULL;
return 0;
}
for(temp=cur=h;temp!=NULL;temp=temp->next)
{
if(temp->d==val)
{
temp=temp->next;
cur->next=temp;
temp->prev=cur;
free(temp);
return 0;
}
}
return 0;
}


int modify(int val,int ele)
{
struct node *temp;
if(h==NULL)
{
printf("THERE is NO NODE TO MODIFY");
return 0;
}
for(temp=h;temp!=NULL;temp=temp->next)
{
if(temp->d==val)
{
temp->d=ele;
return 1;
}
}
printf("THE VAL LOOKING TO MODIFY IS NOT THERE IN THE LIST");
return 0;

}

void display()
{
printf("\r\n");
  struct node *temp;
  for(temp=h;temp!=NULL;temp=temp->next)
  {
    printf("%d \t",temp->d);
  }
}

int main()
{
add_double(10);
add_double(20);
add_double(30);
add_double(40);
add_double(50);
add_double(60);
display();
modify(20,100);

modify(30,200);
modify(40,300);
modify(400,100);
display();
return 0;
}

