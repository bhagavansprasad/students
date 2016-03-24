#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	char p[100];
	struct node *next;
};
struct node *head[26]={NULL};
char
buff[18][100]={{"apple"},{"ball"},{"cat"},{"dog"},{"elephant"},{"owl"},{"york"},{"Fox"},{"bat"},{"COW"},{"ANT"},{"zoo"},{"abc"},{"aaP"}};
main()
{
	int i=0;
	for(i=0;i<12;i++)
	{
		add_node(buff[i]);
	}
	display();
}
int add_node(char *r)
{
	int ha = 0;
	struct node *new,*t;
	ha = gen_key(r);
	printf("key for %s == %d\n",r,ha);
	new=(struct node*)malloc(sizeof(struct node));
	//new->p=malloc(strlen(r)+1);
	strcpy(new->p,r);

	new->next=NULL;
	if(head[ha]==NULL)
	{
		head[ha]=new;
		return 0;
	}
	for(t=head[ha];t->next!=NULL;t=t->next);
	
		t->next=new;
		return 0;
	
}

int gen_key(char *r)
{
	if(r[0]>=65 && r[0]<=90)
	{
		return r[0]-'A';
	}
	else if(r[0]>=97 && r[0]<=122)
	{
		return r[0]-'a';
	}
}

int display( )
{
	int ha; 
	struct node *t;
	for(ha = 0; ha < 26; ha++)
	{
		for(t=head[ha];t!=NULL;t=t->next)
		{
			printf("in header[%d] nodes are === %s, \n",ha,t->p);
		}
}
}
