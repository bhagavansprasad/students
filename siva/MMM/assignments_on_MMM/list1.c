#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert(char *);
void display(void);
int delete(char *);

typedef struct STUDENT
{
	char *s;
	struct STUDENT *next;
}student;

student *head = NULL;

main()
{
char a[10][25] ={"AURA","NETWORKS","BANGALORE","ACCESS","STB","LABS","BANGALORE","NDS","PHILIPS","LG"};
insert(a[0]);
insert(a[1]);
insert(a[2]);
insert(a[3]);
insert(a[4]);
insert(a[5]);
insert(a[6]);
insert(a[7]);
insert(a[8]);
insert(a[9]);

display();
delete(a[7]);


}


int  insert(char *p)
{
	student *new,*temp;

	new = malloc(sizeof(student));

	if(head == NULL)
	{
		new->next = NULL;
		new->s = malloc(strlen(p)+1);
		strcpy(new->s,p);
		head = new;
	}
	else
	{
		for(temp = head; temp->next != NULL; temp=temp->next);
		temp->next = new;
		new->s = malloc(strlen(p)+1);
		strcpy(new->s,p);
		new->next = NULL;
	}
}

void display(void)
{

	student *temp;
   for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%s\n",temp->s);
	}
	printf("\n");
}

int delete(char *p)
{
	student *temp,*old;
	
	for(temp=head;temp!=NULL;)
	{

		if((strcmp(temp->s,p)==0))
		{
			if(temp == head)
			{
				head = temp->next;
				free(temp->s);
				free(temp);
				return;
			}
			else
			{
				old->next = temp->next;
				free(temp->s);
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

