#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	char *tname;
	int info;
	struct node *link;
}node_t;

node_t *head;

void insert_front(char *str,int data)
{
	node_t *temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->tname = malloc(strlen(str)+1);
	strcpy(temp->tname, str);
	temp->info = data;
	temp->link = head;
	head  = temp;
	return;
}

void display()
{
	node_t *temp;
	int i = 1;
	
	if(head == NULL)
	{
		printf("The list is empty---\n");
		return;
	}
	
	printf("The list is----\n");
	for(temp = head;temp;temp = temp->link)
		printf("---> %d.  %s, %d\n",i++,temp->tname,temp->info);
	
	printf("\n");
	return;
}
void insert_rear(char *str,int data)
{
	node_t *temp;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->tname = malloc(strlen(str)+1);
	strcpy(temp->tname,str);
	temp->info = data;
	temp->link = NULL;
	if(head == NULL)
	{
		head = temp;
		return;
	}
	node_t *current;
	current = head;
	
	while(current->link != NULL)
	{
		current = current->link;
	}
	current->link = temp;
	return;
}

int insert_pos(char *str, int data, int pos)
{
	node_t *temp, *current, *prev;
	int count;
	temp = (node_t *)malloc(sizeof(node_t));
	temp->tname = malloc(strlen(str)+1);
	strcpy(temp->tname, str);
	temp->info = data;

	if(head == NULL && pos == 1)
	{
	//	temp->link = NULL;
		head = temp;
		return 0;
	}
	if(head == NULL)
	{
		printf("Invalid position\n");
		return -1;
	}
	if(pos == 1)
	{
		temp->link = head;
		head = temp;
		return 0;
	}
	count = 1;
	current = head;
	prev = NULL;
	
	while(current->link != NULL && count != pos)
	{
		prev = current;
		current = current->link;
		count++;
	}
	
	if(count == pos)
	{
		prev->link = temp;
		temp->link = current;
		return 0;
	}
	
	printf("Invalid position\n");
		return -1;
}
int delete_front()
{
	node_t *temp;
	temp = head;
	if(head != NULL)
	{
		head = head->link;
		free(temp->tname);
		free(temp);
		return 0;
	}
	return -1;
}
int delete_rear()
{
	node_t *current, *prev;
	
	//current = head;
 
	if(head == NULL)
	{
		printf("List is empty can not delete\n");
		return -1;
	}
	
	if(head->link == NULL)
	{
		current = head;
		head = head->link;
		free(current->tname);
		free(current);
		return 0;
	}
	
	prev = NULL;
	current = head;
	
	while(current->link != NULL)
	{
		prev = current;
		current = current->link;
	}
	free(current->tname);
	free(current);
	prev->link = NULL;
	return 0;
}
	
int delete_pos(int pos)
{
	node_t *current, *prev;
	int count;

	if(head == NULL && pos <= 1)
	{
		printf("Invalid position list is empty\n");
		return -1;
	}
	if(pos == 1)
	{
		current = head;
		head = head->link;
		free(current->tname);
		free(current);
		return 0;
	}
	prev = NULL;
	current = head;
	count = 1;
	while(current->link != NULL)
	{
		if(count == pos)
			break;
		count++;
		prev = current;
		current = current->link;
	}
	if(count != pos)
	{
		printf("Invalid position\n");
		return -1;
	}
	prev->link = current->link;
	free(current->tname);
	free(current);
	return 0;
}

		

	

