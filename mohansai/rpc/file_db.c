#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "file_db.h"

file_info *head;

/* this is a linked list*/

int display()
{
	file_info *temp;

	for(temp=head ; temp!=NULL; temp=temp-> next)
	{
//		printf("file_name %s file_des %d file_mode %d\n\r",temp->name,temp->descriptor,temp->mode);
	}
	return 0;
}

int add_fcb_to_list(file_info *fcb)
{
	file_info *temp, *new;

	new = malloc(sizeof(file_info));
	fcb->prev=NULL;
	fcb->next=NULL;

	memcpy(new, fcb, sizeof(file_info));

	if(head == NULL)
		head = new;
	else
	{
		for(temp = head ; temp->next != NULL ; temp = temp->next);
		temp->next = new;
		new->prev  = temp;
	}	

	return 0;
}
int file_remove(int fd)
{
	file_info *temp;

	for(temp=head ; temp!=NULL ; temp=temp->next)
	{
		if(temp->descriptor==fd)
		{
			if(temp==head && temp->next==NULL )
			{
				head=NULL;
				free(temp);
				return 0;
						
			}
			else if(temp==head && temp->next->next == NULL )
			{
				temp->next->prev=NULL;
				head=temp->next;
				free(temp);
				return 0;
			}
			else 
			{
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				free(temp);
				return 0;
			}	
		}
	}
}


file_info * fd_check(int fd)
{
	file_info *temp;

	for(temp = head ; temp != NULL ; temp = temp-> next)
	{
		if(temp->descriptor == fd)	
			return temp;
	}

	return NULL;
}


