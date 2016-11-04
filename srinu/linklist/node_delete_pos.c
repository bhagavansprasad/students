#include <stdio.h>
#include <stdlib.h>
struct student
{
	int no;
	struct student *next;
};
struct student *h=NULL;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);

	printf("before deleting\n");
	display();
	node_delete_pos(1);
	
	printf("after deleting\n");
	display();
}
void display(void)
{
	struct student *t=h;
	while(t!=NULL)
	{
		printf("add_node value: %d        address:  %p        next value:  %p\n",t->no,t->next,t);
		t=t->next;
	}
}
int add_node(int value)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	{
		new->no=value;
		new->next=NULL;
	}
	if(h==NULL)
	{
		h=new;
		return 0;
	}
	t=h;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new;
	return 0;
}
int  node_delete_pos(int pos)
{
	struct student *p,*c;
	int i;
	p=c=h;
	for(i=1;c!= NULL;i++)
	{
		if(pos==i)
		{
			if(pos==1)
			{
				h = c->next;
				free(c);
				return 0;
			}
			else
			{
				p->next = c->next;
				free(c);
			return 0;
			}
		}
		p=c;
		c=c->next;
	}
}
