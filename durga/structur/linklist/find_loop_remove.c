# include<stdio.h>
#include <stdlib.h>

struct node 
{
	int n;
	struct node *p;	
};
struct node *new;
struct node *h = NULL;
int find_loop(void );
void add_loop(void);
void remove_loop(struct node* );
main()
{
	//	struct node *d;
	add(10);
	add(20);
	add(30);
	add(40);
	add_loop();
	int i =	find_loop();
	if(i == 1)
		printf("loop is dected and removed\n");
	else 
		printf("loop is not there\n");
		display();

}


int add( int num)
{
	struct node *temp = h;
	new = malloc(sizeof(struct node));
	new -> n = num;
	new -> p = NULL;
	if( h == NULL)
	{
		h = new;
		return 0;
	}
	while (temp ->p != NULL)
	{
		temp = temp ->p;
	}
	temp ->p = new;
	return 0 ;
}

int display()
{
	struct node *d;
	if( h == NULL)
	{
		printf("list is empty");
	}
	d = h;
	printf("list is\n");
	while 
		( d != NULL)
		{
			printf("%d\n",d -> n);
			printf("------->adres:%u\n",d);
			d = d->p;
		}
	printf("\n");
}

/*function for find_loop*/

int  find_loop()
{
	struct node* first, *second;
	if(h != NULL)
	{
		first = second = h;
		while(first && second && second->p)
		{
			first = first->p;
			second = second->p->p;
			if(first == second)
			{
				remove_loop(first);
				return 1;

			}

		}
		return 0;
	}
}

/*function for add_loop*/
void add_loop(void)
{
	if(h != NULL)
		h->p->p->p = h->p;
}

/* remove loop in linked list*/

void remove_loop(struct node* ptr)
{
	struct node* ptr1 = ptr;
	struct node* ptr2 = ptr;
	int k = 1,i;
	while (ptr1->p != ptr2)
	{
		ptr1 = ptr1->p;
		k++;
	}

	ptr1 = ptr2 =  h;
	for(i = 0; i<k; i++)
	{
		ptr2 = ptr2->p;
	}
	while(ptr2 != ptr1)
	{
		ptr1 = ptr1->p;
		ptr2 = ptr2->p;
	}
	ptr2 = ptr2->p;
	while(ptr2->p != ptr1)
	{
		ptr2 = ptr2->p;
	}
	ptr2->p = NULL;

}

