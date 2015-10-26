#include<stdio.h> 
#include<stdlib.h>

struct node
{
	struct node *p;
	int no;
	struct node *N;
};

struct node *h = NULL;


void dump_list()
{
	struct node *t;

	for(t=h;t!=NULL;t=t->N)
	{
		printf("%5d", t->no);
	}

	printf("\n");
}

void display()
{
	struct node *t;
	for(t=h;t!=NULL;t=t->N)
	{
		printf("%d\n",t->no);
	}
}


int add_node(int value)
{
	struct node *new,*t,*pre;

	printf("adding node with value %d\n", value);


	new = malloc(sizeof(struct node));

	new->p=NULL;
	new->no = value;
	new->N  = NULL;


	if(h == NULL)
	{
		h = new;
		return 0;
	}

	for(t = h; t->N!= NULL;t=t->N);
	t->N = new;
	t->N->p=t;
	return 0;
}


int delete_node(int value)
{
	struct node *curr,*pre;

	printf("deleting node with value %d\n", value);
    curr=h;
    	if(curr->no==value)

			if(curr==h)
			{
				h=curr->N;
				curr->N->p=NULL;
				free(curr);
				return 0;
			}


	for(curr=&value;curr->N!=NULL;curr=curr->N)
	{	
/*	if(curr->no==value)

			if(curr==h)
			{
				h=curr->N;
				curr->N->p=NULL;
				free(curr);
				return 0;
			}


*/			
			if(curr->no==value) 
			{ 
			   if(curr->N==NULL)
			   {
			    pre->N=NULL;
				free(curr);
				return 0;
				}
			 /* else if(curr->N!=NULL)
			    curr->N->p=pre;
				curr->p->N=curr->N;
				free(curr);
				return 0;
			}*/
			else
			    {
				curr->N->p=pre;
				curr->p->N=curr->N;
				free(curr);
				return 0;
                }



/*                else if(curr->no==value)
			   {
			    if(curr->N==NULL)

				curr->N->p=pre;
				curr->p->N=curr->N;
				free(curr);
				return 0;
                }
*/
}
}  

}



int main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
		add_node(50);
		add_node(60);
		dump_list();


/*	add_node(23);
	add_node(36);
	dump_list();
*/
	delete_node(10);
	dump_list();
	
//	delete_node(30);
//	dump_list();

	delete_node(60);
	dump_list();
/*	delete_node(23);
	dump_list();
*/


}


