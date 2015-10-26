#include "stdio.h"
#include "stdlib.h"
struct student
{
	int no;
	struct student *next;
};
struct student *h=NULL;
int add_node(int value);
int add_at_begining(int value);
int add_at_end(int value); 
int add_at_posi(int value,int posi);
int delete_by_val(int val);
//int delbegi(int val);
void display();
int display_index(int value);
main()
{
	int index,val=1000;
	add_node(10);
	add_node(20);
	add_node(30);
	add_at_end(8);
	add_node(40);
	add_node(50);
	add_at_begining(230);
	add_at_end(38);
	add_at_posi(70,4);
	//delbegi(230);
	delete_by_val(30);
	index=display_index(1000);
	display();
	if(index == 0)
	{
		printf("%d is not available in the list \n",val);
	}
	else
	{
		printf("%d index position is = %d\n",val,index);
	}

}
int add_node(int value)
{
	struct student *new,*t;
	new = malloc(sizeof(struct student));
	new->no = value;
	new->next = NULL;
	
	if(h == NULL)
	{
		h = new;
		return 0;
	}
	
/*	t = h;
	while(t->next != NULL)
	{
		t=t->next;
	}
	t->next=new;*/
	for(t = h; t->next != NULL;t = t->next);
	t->next = new;
	return 0;
}
void display() 
{
	struct student *t=h;
	while(t!=NULL)
	{
		printf("%d = %d\n",t->no,t->next);
		t=t->next;
	}
}
int add_at_begining(int value)
{
	struct student *new;
	new=malloc(sizeof(struct student));
	new->no=value;
	new->next=h;
	h=new;
}
int add_at_posi(int value,int posi)
{
	struct student *new,*t;
	int i;
	t=h;
	for(i=1;i<posi-1 && t!=NULL;i++)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("there are no nodes:");
	}
	else
	{
		new=malloc(sizeof(struct student));
		new->no=value;
	}
	if(posi==1)
	{
		new->next=h;
		h=new;
	}
	else
	{
		new->next=t->next;
		t->next=new;
	}
}
int add_at_end(int value)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	new->no=value;
	new->next=NULL;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new;
	return 0;
}
int delete_by_val(int val)
{
	struct student *new,*t;
	if(h==NULL)
	{
		printf("list is empty:");
		return 0;
	}
	while(t->next!=NULL)
	{
		if(t->next->no==30)
		{
			new=t->next;
			t->next=new->next;
			free(new);
			return 0;
		}
		t=t->next;
	}

}
/*int delbegi(int val)
{
	struct student *new;
	new=h;
	h=h->next;
	free(new);
	return 0;
}*/
int display_index(int value)
{
	int c=0, flag = 0;
	struct student *t=h;
	for(t=h; t!=NULL; t=t->next)
	{
		if(t->no==value)
		{
			flag = 1;
		}
		c++;
		if(flag == 1)
			return c;
	}
}
