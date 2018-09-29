#include<stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *new;
struct node *start=NULL;
struct node *reverse(struct node *h);
main()
{ 
	insertInAscOrder(10);
	insertInAscOrder(20);
	insertInAscOrder(15);
	insertInAscOrder(5);
	insertInAscOrder(12);
	display(start);
}
int display(struct node *start)
{
	struct node *t;
	for(t=start;t!=NULL; )
	{
		printf("%d\n",t->info);
		t=t -> next;
	}
}

void insertInAscOrder(int val) 
{
    struct node *new1;
   struct node *temp;
    struct node *previous; 

    //create new node
    new1 = (struct node *)malloc(sizeof(struct node)); 

    //check whether node is created or not
    if(new1 == NULL) 
    {
        printf("Insufficient memory.");
        return;
    }   

    //Updating different parts of the node
    new1 -> info = val;
    new1 -> next = NULL;    

    //checking whether the node created is only node or not
    if (start == NULL) 
    {       
        start = new1;
    } 
    //If value is less than the value of first node
    else if(val < start -> info) 
    {
        new1 -> next = start;
        start = new1;
    } 
    else 
    {   
        previous = start;
        temp = start -> next;


            //Go to the position where node is to be inserted
            while(temp != NULL && val > temp -> info) 
            {
                previous = temp;
                temp = temp -> next;
            }


            //Insert the node at particular position
           if(temp == NULL) 
           {
                   previous -> next = new1;
           } 
           else 
           {
                   new1 -> next = temp;
               previous -> next = new1;
           }
    }
}
