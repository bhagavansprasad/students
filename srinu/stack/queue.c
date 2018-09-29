#include <stdio.h>
#include <stdlib.h>
int pop(void );
struct student
{
	int val;
	struct student *link;
};
struct student *h=NULL;
main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	display();
	printf("\n");
	pop();
	pop();
	//pop();
	//pop();
	//pop();
	display();
}
int push(int val)
{
	struct student *new,*t;
	new=malloc(sizeof(struct student));
	new->val=val;
	new->link=NULL;
	if(h==NULL)
	{
		h=new;
		return(0);
	}
	for(t=h;t->link!=NULL;t=t->link);
	t->link=new;
}
void display()
{
	struct student *p;
	for(p=h;p!=NULL;p=p->link)
	{
		printf("%d\n",p->val);
	}
}
int pop(void)
{
	struct student *tmp;
	tmp=h;
	if(tmp->link==NULL)
	{
		printf("queue is empty\n");
		h=NULL;
i		free(tmp);
		return 0;
	}
	h=tmp->link;
	free(tmp);
}

