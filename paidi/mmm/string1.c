#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(char *);
void display(void);
void delete(void);
typedef struct names
{
	char name[20];
	struct names *next;
}names;

names *head = NULL;
main()
{
char a[10][20] ={"aura",
                 "hello",
				 "world",
				 "sudheer",
				 "children",
				 "bangalore",
				 "Hyderabad",
				 "Electronics",
				 "documents",
				 "bye"};
int i;
for(i = 0;i <=9; i++)
add(a[i]);
display();
delete();
display();
}
void add(char *p)
{
	names *new,*temp;
	new = malloc(sizeof(names));
	if(head == NULL)
	{
		new->next = NULL;
		strcpy(new->name,p);
		head = new;
	}
	else
	{
		for(temp = head; temp->next != NULL; temp=temp->next);
		temp->next = new;
		strcpy(new->name,p);
		new->next = NULL;
	}
}
void display(void)
{
	names *temp;
	temp = head;
	while(temp != NULL)
	{
		printf("%s\n",temp->name);
		temp = temp->next;
	}
}
void delete(void)
{
	names *temp,*old;
	temp = head;
	char str[20];
	printf("enter the name to delete\n");
	scanf("%s",str);
	while(temp != NULL)
	{
		if(!(strcmp(temp->name,str)))
		{
			if(temp == head)
			{
				head = temp->next;
				free(temp);
				return;
			}
			else
			{
				old->next = temp->next;
				free(temp);
				return;
			}
		}
		else
		{
			old = temp;
			temp = temp->next;
		}
	}
}


