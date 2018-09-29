#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display(void);
int delet(void);
int add(char *);

typedef struct names
{
	char *s;
	struct names *next;

}names;
names *head=NULL;

main()
{
	int i;
	char a[10][25]={"paidi","prem","ravi","siva","sudha","mohan","tarun","aura","network","teja"};
	for(i=0;i<=9;i++)
	{
		add(a[i]);
	}
	
	display();
	delet();
	display();

}
int add (char *p)
{
	names *new=NULL,*temp=NULL;
	new=malloc(sizeof(names));
	new->s=malloc(strlen(p));
	strcpy(new->s,p);
	if(head==NULL)
	{
		head=new;
		new->next=NULL;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=new;
		new->next=NULL;

	}

}

void display(void)
{
	names *temp=NULL;
	temp=head;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%s\n",temp->s);
	}
	printf("\n");

}

int delet(void)
{
	names *temp=NULL,*new=NULL,*old=NULL;
    char str[25];
	printf("enter the name to delet\n");
	scanf("%s",str);
	for(temp=head;temp->next!=NULL;)
	{
		if((strcmp(temp->s,str)==0))
		{ 
			if(head==temp)
			{
				head=temp->next;
				free(temp);
				return;
			}
			else
			{
				old->next=temp->next;
				free(temp);
				return;

			}

		}
		else
		{
			old=temp;
			temp=temp->next;
		}

	}
}



