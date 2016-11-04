#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *next;
};
struct node *h = NULL;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(40);
	add_node(40);
	add_node(50);
	display();
	creating_loop();
	finding_loop();
}
void display(void)
{
	struct node *t=h;
	if(t==NULL)
	{
		printf("no elements to printn");
	}
	while(t!=NULL)
	{
		printf("no-->%d\n", t->no);
		t = t->next;
	}
}
int add_node(int n)
{
	struct node *new;
	new= malloc(sizeof(struct node));
	new->no = n;
	new->next = NULL;
	struct node *t;

	if(h == NULL)
	{
		h = new;
		return 0;
	}
	for(t=h;t->next!=NULL;t=t->next);
	t->next=new;
	return 0;
}
void creating_loop()
{
	int i;
	struct node *t = h;
	for(i=1;i<5;i++)
	{
		printf("i------>      %d\t        t--------->no-----> : %d\n",i,t->no);
		t = t->next;
	}
	t->next = h->next;
	printf("                     t------->no----------> : %d\n",t->no);
}
void finding_loop()
{
	struct node *t,*p;
	t=p=h;
	while(t!=NULL)
	//for(t=h,p=h;t!=NULL;p=p->next->next,t=t->next)
	{
		t=t->next;
	
		p=p->next->next;

		if(t==p)
		{
		printf("       loop found         \n ");
		break;
		}
	}
}
