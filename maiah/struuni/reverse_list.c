#include<stdio.h> 
#include<stdlib.h>
int add_node(int value);
void reverse_list(void);
void display(void);

struct node
{
   int no;
   struct node *next;
};
struct node *h=NULL;
main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	reverse_list();
	display();
}

int add_node(int value)
{
	struct node *new,*t; 
    new=malloc(sizeof(struct node));
    new->no=value;
	new->next=NULL;

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

void reverse_list()
{
    struct node *t,*temp1,*new;
    t=h;
    new=NULL;
    while(t!=NULL)
    {
         temp1=new;
         new=t;
         t=t->next;
         new->next=temp1;
    }
    h=new;
}

void display(void)
{
    struct node *t=h;
	printf("the reverse list is:\n");
    while(t!=NULL)
    {
         printf("%d\n",t->no);
         t=t->next;
    }
}
