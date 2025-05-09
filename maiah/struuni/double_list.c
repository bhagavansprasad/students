#include<stdio.h>
#include<stdlib.h> 
struct node
{
     struct node *previous;
     int no;
     struct node *next;
}*head, *last; 

void add_at_begining(int value)
{
    struct node *new,*t;
     new=malloc(sizeof(struct node));
     new->no=value;
     if(h==NULL)
     {
         h=new;
         h->previous=NULL;
         h->next=NULL;
         last=head;
     }
     else
     {
         temp=var;
         temp->previous=NULL;
         temp->next=head;
         head->previous=temp;
         head=temp;
     }
} 

void insert_end(int value)
{
     struct node *var,*temp;
     var=(struct node *)malloc(sizeof(struct node));
             var->data=value;
     if(head==NULL)
     {
          head=var;
          head->previous=NULL;
          head->next=NULL;
          last=head;
     }
     else
     {
         last=head;
         while(last!=NULL)
         {
             temp=last;
             last=last->next;
         }
     last=var;
     temp->next=last;
     last->previous=temp;
     last->next=NULL;
     }
}   

int insert_after(int value, int loc)
{
     struct node *temp,*var,*temp1;
     var=(struct node *)malloc(sizeof(struct node));
     var->data=value;
         if(head==NULL)
     {
           head=var;
           head->previous=NULL;
           head->next=NULL;
     }
     else
     {
           temp=head;
           while(temp!=NULL && temp->data!=loc)
           {
                 temp=temp->next;
           }
           if(temp==NULL)
           {
                printf("\n%d is not present in list ",loc);
           }
           else
           {
           temp1=temp->next;
           temp->next=var;
           var->previous=temp; 
          var->next=temp1;
           temp1->previous=var;
           }
     }
     last=head;
     while(last->next!=NULL)
     {
           last=last->next;
     }
}   
int delete_from_end()
{
      struct node *temp;
      temp=last;
      if(temp->previous==NULL)
      {
           free(temp);
           head=NULL;
           last=NULL;
           return 0;
      }
      printf("\nData deleted from list is %d \n",last->data);
      last=temp->previous;
      last->next=NULL;
      free(temp);
      return 0;
} 

int delete_from_middle(int value)
{
    struct node *temp,*var,*t, *temp1;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data == value)
        {
             if(temp->previous==NULL)
             {
                  free(temp);
                  head=NULL;
                  last=NULL;
                  return 0;
             }
             else
             {
                  var->next=temp1;
                  temp1->previous=var;
                  free(temp);
                  return 0;
             }
        }
        else
        {
              var=temp;
              temp=temp->next;
              temp1=temp->next;
        }
    }
    printf("data deleted from list is %d",value);
}  

void display()
{
     struct node *temp;
     temp=head;
     if(temp==NULL)
      {
         printf("List is Empty");
      }
     while(temp!=NULL)
     {
          printf("-> %d ",temp->data);
          temp=temp->next;
     }
} 

