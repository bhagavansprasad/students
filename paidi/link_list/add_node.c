#include<stdio.h>
#include<stdlib.h>
int add(int);
void display();
typedef struct node
{
  int data;
  struct node *next;
}node;
node *head = NULL;
int add(int x)
{
   node *temp,*new,*old;
   new = malloc(sizeof(node));
   printf("-->%s %d, :%d\n", __FUNCTION__, __LINE__, x);
   new->data = x;
   new->next = NULL;
   if(head == NULL)
   {
     head = new;
     return 0; 
   }
  for(temp=head;temp->next!=NULL;temp=temp->next);
  temp->next = new;
}

 void display()
{
	node *temp;	
	temp=head;

	printf("-->%s\n", __FUNCTION__);

	while(temp!=NULL)
	{
		printf("%4d",temp->data);
		temp=temp->next;	 
	}

	printf("\n");

}

main()
{
add(10);
add(20);
add(30);
add(40);
add(50);
add(60) ;
add(70);
display();
}
