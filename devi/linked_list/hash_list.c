#include <stdio.h>
#include "stdlib.h"
#include <string.h>
void display();
struct node
{
	char str[20];
	struct node *n;
};
struct node *h[2] = {NULL,NULL};
main()
{
	add_node("devi",0);
	add_node("salma",0);
	add_node("Rumana",0);
	add_node("haritha",1);
	add_node("Reddamma",1);
	add_node("supraja",1);
	display();
}

int add_node(char *s,int i)
{
	struct node *new = (struct node *) malloc(sizeof(struct node));
	strcpy(new->str,s);
	new->n = NULL;
	struct node *t;

	if(h[i] == NULL)
	{
		h[i] = new;
		return 0;
	}
	for(t=h[i];t->n!=NULL;t=t->n);
	t->n=new;

	return 0;

}

void display()
{
	struct node *t[2];
	int i;
	for(i=0;i<2;i++)
	{
	t[i] = h[i];
	if(t[i]==NULL)
	{
		printf("no elements to print\n");
		break;
	}
	while(t[i]!=NULL)
	{
		printf("no-->%s\n", t[i]->str);
		t[i] = t[i]->n;
	}
	}
}
