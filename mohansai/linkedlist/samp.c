#include "stdio.h"
#include "stdlib.h"
struct emp
{
	int age;
	char name[10];
	struct emp *next;
};
struct emp *head = NULL;
void addatbeg(int val); 			/* add   the variables at the biginning*/
void addafter(int loc,int val); 	/* add the node at middle */
void add(int val);					/* adding  the variables at the last*/
void display(); 					/* display the content in the list */
void display_loc(int val);		
void delete(int val); 				/* delete the variable in the list*/
int count();

int main()
{
	int i,num,ret;
	char name[10];

	add(10);
	add(20);
	add(30);
	add(50);
	
	addatbeg(999);
	//addatbeg(1021);
	
	addafter(1,2);
	//addafter(4,1);
	//addafter(2,200); 
	//display_loc(200);
	delete(2);
	display();
	i= count();
	printf("count-->:- %d\n\r",i);

}

void addatbeg( int val) /* add   the variables at the beginning*/
{
	struct emp *new;

	new=malloc(sizeof(struct emp));
	new->age=val;
	new->next=head;
	head=new;
	//printf("adding the node at the  beginning :-new->age  :%d\r\n", new->age);
}

void addafter(int loc,int val) /* add the node at middle */
{
	struct emp *new,*temp;
	int i;
	temp=head;
	
	new=malloc(sizeof(struct emp));
	new->age=val;
	
	for( i = 1 ; i <= loc-1 ; i++ )
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("the element in the list is empty");
			temp->next=new;
			new->next=NULL;
		
		}
	}	
		if(loc==1)
		{
			new->next=head;
			head=new;
		}
		else
		{	
			temp=new;
			new->next=temp;
		}

}

void add(int val)	/* adding  the variables at the last*/
{
	struct emp *new,*temp;
	
	new = malloc(sizeof(struct emp));
	new->age=val;
	new->next=NULL;

	if(head==NULL)
	{	
		head=new;
	//	printf("head->age  :%d\r\n", head->age);
	}
	else
	{
		for(temp = head ; temp->next != NULL ; temp=temp->next);
		temp->next=new;
		//printf("these is add node :-temp->age  :%d\r\n", temp->age);
	}
}

void display() /* display the content in the list */
{
	struct emp *temp=head ;
	
	//printf("hellowtemp->age  :%d\r\n", temp->age);
	if(temp == NULL)
	  printf("there is no content in list\r\n");
	    
	for(temp = head ; temp != NULL ; temp=temp->next)
	{
		printf("display temp->age  :%d\r\n", temp->age);
		//printf("display temp->next :%p\r\n", temp->next);

	}	
}


void delete(int val)
{
	struct emp *temp, *old;

	for( temp=head ; temp != NULL ; temp = temp->next )
	{
		if(temp->age==val)
		{
			if(temp==head)
			{
				head=temp->next;
				printf("headtemp->age  :%d\r\n", temp->age);
				free(temp);
				return;
			}
			else
			{
				old->next=temp->next;
				printf("temp->age  :%d\r\n", temp->age);
				free(temp);
				return;
			}
		}
		else
			old=temp;
	}
}



void display_loc(int val)
{
	struct emp *temp;
	
	int i;

		for( temp=head ; temp != NULL ; temp=temp->next )
		{
			//temp=temp->next;
			if(temp->age==val)
			{
				printf("the element in the specific location temp->age:-%d\n\r",temp->age);
			}
		}
				printf("the element is not in the list val:- %d\r\n",val);
}

int  count () 
{
	struct emp *temp=head;
	int count=0;
	//for( ; temp->next!=NULL; temp=temp->next);
	
	for(temp = head ; temp != NULL ; temp=temp->next)
	{
		count++;
	
	//	printf("count--> %d\n\r",count);
	}
	return count;
}


