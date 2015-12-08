#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *h=NULL;
void removeDuplicates()
{
    struct node* t;
    struct node* new;
    if (h== NULL)
	{
       //return;
	}
	else
	{
	   t=h;
    while (t->next != NULL)
    {
       if (t->data ==t->next->data)
       {           
           new= t->next->next;
           free(t->next);
           t->next = new; 
       }
       else
       {
          t = t->next;
       }
    }
	}
}
 int push(int n)
{
     struct node* new,*t;
     new=malloc(sizeof(struct node));
     new->data  = n;
     new->next =NULL; 
	 if(h==NULL)
	 {
          h= new;
		  return 0;
	 }
	 else
	 {
	 t=h;
	 while(t->next!=NULL)
	 {
	 t=t->next;
	 }
	
	 t->next=new;
	 }
	 return 0;
}
 void display()
{
 struct node *t;
 t=h;
    while (t!=NULL)
    {
       printf("%d ", t->data);
       t= t->next;
    }
}
 int main()
{
 //    struct node* h = NULL;
    push(20);
    push(13);
    push(13); 
    push(11);
    push(11);
    push(11);                                   
    printf("\n Linked list before duplicate removal  ");
    display();
	removeDuplicates();
    printf("\n Linked list after duplicate removal ");        
    display();           
     return 0;
}
