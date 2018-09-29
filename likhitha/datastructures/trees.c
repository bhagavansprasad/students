#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root;

main()
{
	int a;
	printf("size of struct is : %d\n",sizeof(struct node));
	printf("5,2,7,4,9\n");
	insert(&root,5);
	insert(&root,2);
	insert(&root,7);
	insert(&root,4);
	insert(&root,9);

	printf("Preorder : ");
	preOrder(root);
	printf("\n");

	mirror (root);

	printf("Mirror : ");
	preOrder(root);
	printf("\n");

	printf("Inorder : ");
	InOrder(root);
	printf("\n");

	printf("postorder : ");
	postOrder(root);
	printf("\n");

	a=element(root);
	printf("elements are : %d\n",a);

}


int insert(struct node **tempnode,int n)
{
	struct node *temp=NULL;
	if(*tempnode==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=n;
		temp->left=NULL;
		temp->right=NULL;
		*tempnode=temp;
	}
	else if(n < (*tempnode)->data)
	{
		insert(&(*tempnode)->left, n);
	}
	else
	{
		insert(&(*tempnode)->right, n);
	}

}

int preOrder(struct node* r)
{
	if(r!=NULL)
	{
		printf("%d ", r->data);
		preOrder(r->left);
		preOrder(r->right);

	}
}


int InOrder(struct node* r)
{
	if(r!=NULL)
	{
		InOrder(r->left);
		printf("%d ", r->data);
		InOrder(r->right);

	}
}


int postOrder(struct node* r)
{
	if(r!=NULL)
	{
		postOrder(r->left);
		postOrder(r->right);
		printf("%d ", r->data);

	}
}

int element(struct node *r)
{
	if(r)
	{
		return(element(r->left))+1+(element(r->right));
	}
}

int mirror(struct node *r)
{
	if(r==NULL)
		return;
	else
	{
		struct node *temp;
		mirror(r->left);
		mirror(r->right);
		temp=r->left;
		r->left=r->right;
		r->right=temp;
	}
}
