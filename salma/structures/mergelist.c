#include<stdio.h>
#include<stdlib.h>
int add(int,int);
struct node1
{  
	int n;
	struct node1 *p;
};
struct node1 *h1=NULL;
//struct node1 *h2=NULL;
void display(struct node1 *t);
main()
{
	add(10,1);
	add(20,1);
	add(30,1);
	add(40,1);
	add(50,1);
	display(h1);
/*	add(1,2);
	add(2,2);
	add(3,2);
//	display(h2);*/
}
int add(int v,int x)
{
	if(x==1)
	{
	printf("%d\n", x);

		struct node1 *temp=h1;
		struct node1 *new;
	
		new = (struct node1*)malloc(sizeof(struct node1));
		
		new->n = v;
		printf("%d\n", new->n);
		new->p = NULL;
		printf("%u\n", new->p);
		
		if(h1 == NULL)
		{
			printf("%u\n",new);
			h1 = new;
			return 0;
		}
		while(temp != NULL)
			temp = temp->p;
			printf("%u\n",new);
		temp->p = new;
		printf("%u\n", temp->p);
		return 0;
	}
	/*else
	{
		struct node1 *temp=h2;
		struct node1 *t2;
		t2=malloc(sizeof(struct node1));
		t2->n=v;
		t2->p=NULL;
		if(h2==NULL)
		{
			h2=t2;
			return 0;
		}
		while(temp!=NULL)
			temp=temp->p;
		temp->p = t2;
		return 0;
	}*/
}
void display(struct node1 *t)
{
	struct node1 *temp=t;
	while(temp!=NULL)
	{
		printf("%u\t%u \n",temp,temp->p);
		printf("%d \n",temp->n);
		temp = temp->p;
	}
}
