#include <stdlib.h>
#include "stdio.h"
typedef struct emp
{
	int age;
	struct emp *next;
}emp; 
emp *head=NULL;

int display();
void add(int val);
main()
{
	int count;
	add(10);
	add(6);
	add(7);
	add(3);
	add(20);
	add(57);
	
	count=display();
	printf("-->count: %d\n\r",count);
}
void add(int val)
{
	emp *new,*temp;

	new=malloc(sizeof( emp));
	new->age=val;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		
		for( temp =head ; temp->next != NULL ; temp = temp->next );
		temp->next=new;
	}
}
int display()
{
	int count;
	emp *temp;

	for( temp = head ;temp != NULL ; temp = temp->next ) 
	{
		printf("the linked list %d\n\r",temp->age);
		count++;
	}
	return count;
}









