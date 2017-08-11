#include <stdio.h>
#include <stdlib.h>
  typedef struct dd
  {
  struct dd *prev;
   int data;
   struct dd *next;
  }dd1;
  dd1 *head = NULL;
  dd1 * last = NULL;

void insert_dd(int n)
{
	dd1 *temp;
	temp = malloc(sizeof(dd1));
	temp->data = n;

	if(head == NULL)
	{
		temp->prev = NULL;
		head = temp;
	}
	else
	{
		dd1 *temp1 = head;
		while(temp1->next != NULL)
		{
			temp1 = temp1->next ;
		}
		temp1->next = temp;
		temp->prev = temp1;
  }
 }
 void reverse()
  {
    dd1 *temp =NULL;
    dd1	*cur = head;
	while(cur != NULL)
	{
	   temp = cur->prev;
	   cur->prev = cur->next;
	   cur->next = temp;

	   cur = temp;
	}

   //if(temp != NULL)
   //head = temp->prev;
   
  }
void delete_dd(int n)
{
	if(head == NULL)
		printf("ll is empty");
	else
	{
		dd1 *temp = head;
		while(temp->data != n)
		{
			if(temp->next == NULL)
				printf("not found");
			else
				temp=temp->next;
		}
		if(temp == head)
		{
			head = NULL;
			free(temp);
		}

		else
		{
			temp->prev->next = temp->next;
			free(temp);
		}
	}
  }
void display()
{
	dd1 *temp = head;
	if(head == NULL)
		printf("empty");
		else
		{
	while(temp->next != NULL)
	{
		printf(" %d ",temp->data);
	    temp = temp->next;
	}
		printf(" %d ",temp->data);
	}
}
 

  main()
  {
  insert_dd(4);
  insert_dd(6);
  insert_dd(8);
  insert_dd(10);
  insert_dd(2);
  display();
  delete_dd(8);
  printf("after delete\n");
  display();
  reverse();
  printf("\nafter reverse:");
  display();
  }

