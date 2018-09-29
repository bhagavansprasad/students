//sorting single linked list in ascending order based on user input
#include<stdio.h>
#include<stdlib.h>
void display(void);
int  add(int value);
struct node
{
int n;
struct node *p;
};
struct node *h=NULL;
main()
{
int n,i,a;
printf("enter no of arguments to be stored in a linked list : ");
scanf("%d",&n);
printf("enter %d no of elements for linked list \n",n);
 for(i=1;i<=n;i++)
 {
   printf("enter %d element for linked list :",i);
   scanf("%d ",&a);
   add(a);
 }
printf("elements inserted are : \n");
display();
}

int  add(int value)
{
 struct node *new;
 struct node *temp = h;
  
  new= malloc(sizeof(struct node));
  new->n = value;
  new->p = NULL;
 
 if(h == NULL)
 {
   h = new;
   return 0;
 }
//  for(temp;temp != NULL ;temp=temp->p)
 // {
     if(temp->n > new->n)
	 {
          new->p = temp;
		  h = new;
          return 0;
	 }
       
	 else if(temp->n < new->n) 
	 { 
	     for(; temp->p != NULL ; temp=temp->p)

		 {
          if(temp->p == NULL)
		  {
            temp->p = new;
             return 0;
		  }

         else if(temp->p != NULL)
		 {
              if(temp->p->n > new->n)
	  		  {  
                 new->p = temp->p;
				 temp->p = new ;
                   return 0;
			  }
		 }
		 }
	 }
  //}

}




void display(void)
{
struct node *temp=h;
for(temp; temp != NULL ; temp=temp->p)
 printf("%d\t",temp->n);
}

