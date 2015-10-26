#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linstr.h"

int get_hash_key(char ch)
{
	if( ch >= 'A' && ch <= 'Z')
		return ch-'A';
	else if( ch >= 'a' && ch <= 'z')
		return ch-'a';
	else
		return 25;
}

void display(emp *node) /* display the content in the list */
{
	if(node == NULL)
		printf("there is no content in list\r\n");

	for( ; node != NULL ; node = node->next)
	{
		printf("display temp->age  :%s\r\n", node->name);

	}	
}
void delete(char *str)
{
	emp *temp, *old,*h=NULL;
	int i=0,key=0;

	key = get_hash_key(str[0]);
	h = head[key];

	for( temp=h ; temp != NULL ; temp = temp->next )
	{
		if( strcmp(temp->name, str) == 0 )
		{
			if(temp==h)
			{
				h=temp->next;
				free(temp->name);
				free(temp);
				return;
			}
			else
			{
				old->next=temp->next;
				free(temp->name);
				free(temp);
				return;
			}
		}
		else
			old=temp;
	}
}

void add(char *str, int len)	/* adding  the variables at the last*/
{
	emp *h = NULL;
	emp *new, *temp;
	int key = 0;

	new = malloc(sizeof(emp));
	new->name = malloc(len);
	strcpy(new->name, str);
	new->next = NULL;

	key = get_hash_key(new->name[0]);
	h = head[key];
	if(h == NULL)
		head[key] = new;
	else
	{
		for(temp = h ; temp->next != NULL ; temp=temp->next);
		temp->next=new;
	}
}

int main()
{
	add("hi welcome to aura ", strlen("hi welcome to aura "));
	add("aura welcomes u ", strlen("aura welcomes u  "));
	add("hello world", strlen("hello world"));

	add("there is a lot of space", strlen("there is a lot of space "));
	add("nn the world", strlen("nn the world"));
	add("quit from aura", strlen("quit from aura"));
	add("zebra", strlen("zebra"));
	add("1zebra", strlen("1zebra"));

	printf("\n");
	display(head[0]);
	printf("\n");
	display(head[1]);
	printf("\n");
	display(head[2]);
	printf("\n");
	display(head[3]);
	printf("\n");
	display(head[4]);
	printf("\n");
	display(head[5]);
	printf("\n");
	display(head[6]);
	printf("\n");
	display(head[7]);
	printf("\n");
	display(head[8]);
	printf("\n");
	display(head[9]);
	printf("\n");
	display(head[10]);
	printf("\n");
	display(head[11]);
	printf("\n");
	display(head[12]);
	printf("\n");
	display(head[13]);
	printf("\n");
	display(head[14]);
	printf("\n");
	display(head[15]);
	printf("\n");
	display(head[16]);
	printf("\n");
	display(head[17]);
	printf("\n");
	display(head[18]);
	printf("\n");
	display(head[19]);
	printf("\n");
	display(head[20]);
	printf("\n");
	display(head[21]);
	display(head[22]);
	printf("\n");
	display(head[23]);
	printf("\n");
	display(head[24]);
	printf("\n");
	display(head[25]);
	printf("\n");

	return 0;
}
