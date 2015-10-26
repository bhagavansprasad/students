#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *n;
};
struct node *h = NULL;
void display(void)
{
	struct node *t=h;
	if(t==NULL)
	{
		printf("no elements to print\n");
	}
	while(t!=NULL)
	{
		printf("no-->%d\n", t->no);
		t = t->n;
	}
}

int add_node(int n)
{
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->no = n;
	new->n = NULL;
	struct node *t;

	if(h == NULL)
	{
		h = new;
		return 0;
	}
	for(t=h;t->n!=NULL;t=t->n);
	t->n=new;

	return 0;

}





void creating_loop()
{
	int i;
	struct node *t = h;
	for(i=1;i<5;i++)
	{
		printf("i-->%d\tt->no-->%d\n",i,t->no);
		t = t->n;
	}
	t->n = h->n;
	printf("t->no-->%d\n",t->no);
}


void finding_loop()
{
	struct node *t,*p;
	for(t=h,p=h;t!=NULL;p=p->n->n,t=t->n)
	{
		if(t==p)
		{
		printf("loop found");
		break;
		}
	}
}


main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	display();
	creating_loop();
	finding_loop();
	//display();
}

