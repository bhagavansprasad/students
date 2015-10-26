#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LIST_SIZE 27

int addnode(char *);
int hashkeygen(char *);
void display();

typedef struct NODE
{
	char *s;
	struct NODE *next;
}node;

node *hlist[HASH_LIST_SIZE]={NULL};

char *buff[]={"A-apple","H-horse","f-frog", "t-toss","a-angry", "12345"};

main()
{
	int i;
	printf("---%ld\n",sizeof(buff)/4);
	for(i=0;i<(sizeof(buff)/sizeof(char *));i++)
	{
//    	printf("%----> %d:%s\n",i,buff[i]);
		addnode(buff[i]);
	}
	display();
}
int addnode(char *p)
{

	int hk;
	node *new,*temp;
	new=malloc(sizeof(node));
	new->next=NULL;
	new->s=malloc(strlen(p)+1);
	strcpy(new->s,p);
	hk=hashkeygen(p);

	if(hlist[hk]==NULL)
	{
		hlist[hk]=new;
		return 0;
	}

	for(temp=hlist[hk];temp->next!=NULL;temp=temp->next);
	temp->next=new;
	return 0;
}
int hashkeygen(char *p)
{

	if(p[0]>='A'&&p[0]<='Z')
		return(p[0]-'A');
	else if(p[0]>='a'&&p[0]<='z')
		return(p[0]-'a');
	else
		return HASH_LIST_SIZE-1;
}

void display()
{

	node *temp;
	int i;
	for(i=0;i<=HASH_LIST_SIZE;i++)
	{
		if(hlist[i]!=NULL)
		{
			temp=hlist[i];
			printf(":%c are ---->",i+65);
			for(temp=hlist[i];temp!=NULL;temp=temp->next)
			{
				printf("%s",temp->s);
			}
			if(hlist[i]!=NULL)
				printf("\n");
		}
	}
}
