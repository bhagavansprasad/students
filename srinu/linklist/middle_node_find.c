#include <stdio.h>
#include <stdlib.h>
struct node
{
	int no;
	struct node *next;
};
struct node *h=NULL;
void display();
main()
{
	middlenode(10);
	middlenode(20);
	middlenode(30);
	middlenode(40);
	middlenode(50);
	display();
}
int middlenode(int n)
{
	struct node *new,*p;
	new=malloc(sizeof(struct node));
	p=new;
	new=new->next->next;
	while(new!=NULL)
	{
		new=new->next;
		p=p->next;
	}
}
void display()
{
	struct node *t;
	t=h;
	while(t!=NULL)
	{
		printf("%d\n",t->no);
		t=t->
