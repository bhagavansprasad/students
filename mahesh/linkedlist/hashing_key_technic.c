#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LIST_SIZE 32

int addnode(char *);
int hashkeygen(char *);
void display();
typedef struct NODE
{
	char *s;
	struct NODE *next;
}node;

node *hlist[HASH_LIST_SIZE]={NULL};

char *buff[] = {"A-addnode", "a-add", "A-andriod", "B-buffer", "b-buildtag", "C-convert", "c-color", "E-edit", "e-exit","D-diff","r-redo","S-syntax","j-junk","h-hashing","t-tools","p-prem","paidi","sudhir","bhagavansir","linkedlist","hashkey","kumar","p-paidi","ravi", "Aura Networks", "Linked List", "12345","Zoo", "sudhakar","find","global","int","menu","next","operator"};
main()
{
	int i;
	printf("-->%ld\n", sizeof(buff)/4);

	for(i = 0; i < (sizeof(buff)/sizeof(char *)); i++)
	{
		//printf("-->%d :%s\n", i, buff[i]);
		addnode(buff[i]);
	}

display();
}

int addnode(char *p)
{
	int hl;
	node *new,*temp;

	new = malloc(sizeof(node));
	new->s = malloc(strlen(p)+1);
	new->next = NULL;
	strcpy(new->s,p);

	hl = hashkeygen(p);

	if(hlist[hl] == NULL)
	{
		hlist[hl] = new;
		return 0;
	}

	for(temp = hlist[hl]; temp->next != NULL; temp = temp->next);
	temp->next = new;

	return 0;
}

int hashkeygen(char *p)
{
	if(p[0] >= 'A' && p[0] <= 'Z')
		return (p[0] - 'A');
	else if(p[0] >= 'a' && p[0] <= 'z')
		return (p[0]-'a');
	else 
		return HASH_LIST_SIZE-1;
}

void display()
{
	node *temp;
	int i;
	for(i=0; i <= HASH_LIST_SIZE; i++)
	{
		if(hlist[i] != NULL)
		{
			temp=hlist[i];

			printf(": %c are----->",i+65);

			for(temp=hlist[i];temp!=NULL;temp=temp->next)
			{
				printf(" %s ",temp->s);
			}
			if(hlist[i]!=NULL)
				printf("\n");
		}
	}
}
