#include "list.h"

struct data *head=NULL;

int append_node(int n,void *p)
{
	struct data *temp,*new;
	printf("Enter APPENd Module:\n");
	new = malloc(sizeof(struct data));
	new->val = n;
	new->pMaddress = p;
	new->next=NULL;

	if(head == NULL)
	{
		head =new;
		return 0;
	}
	else
	{
		for(temp=head; temp->next!=NULL; temp=temp->next);
		temp->next = new;
		printf("Returned Append_Node :\n");
	}
	
}


void delete_node(void *p)
{
	struct data *temp,*previous;
	printf("Entere Delete_Node :\n");
	for(temp=head;temp!=NULL;)
	{
		if(temp->pMaddress == p)
		{
			if(temp== head)
			{
				head = NULL;
				free(temp);
				return;
			}
			else
			{
				previous->next=temp->next;
				free(temp);
			}
		}

		else
		{
			previous=temp;
			temp=temp->next;
		}

	}
	printf("Returned Delete_Node :\n");
}

void display_node()
{
	printf("enter display\n");
	struct data *temp;
	for (temp = head ;temp!=NULL;temp=temp->next)
	{
		printf("Size= %d\t",temp->val);
		printf("ADDRESS = %u\n",temp->pMaddress);
	}
	printf("\n");
	printf("Returned Display_Node\n");
}

