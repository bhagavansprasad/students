#include <stdio.h>
#include <stdlib.h>


typedef struct tree
{
	int data;
	struct tree *left,*right;	
 }tree1;

tree1 *root = NULL;
void preorder_tree(tree1 *tree2)
{
	tree1 *temp = tree2;
	if(temp)
	{
		printf("  %d ",temp->data);
		preorder_tree(temp->left);
		
		preorder_tree(temp->right);
	}
}

void mirror(tree1 *tree2)
{
	if(tree2 == NULL )
		return;

	else
   {
	   tree1 *temp;
	   mirror((tree2)->left);
	   mirror((tree2)->right);
	   temp = tree2->left;
	   tree2->left=tree2->right;
	   tree2->right=temp;

  }
}
int size(tree1 *tree2)
{
	if(tree2)
		return (size(tree2->left)+1+size(tree2->right));

}
int depth(tree1 *tree2)
{
	if(tree2)
	{
		int l=depth(tree2->left);
		int r=depth(tree2->right);
		if(l>r)
			return (l+1);
		else
			return (r+1);
 }
}
void min_tree()
{
	tree1 *temp=root;
	while(temp->left !=NULL)
	{
		temp=temp->left;
	}
	printf(" min=%d",temp->data);
}

void insert_tree(tree1 **tree2 , int val)
  {
    tree1 *temp = NULL;
	temp =(tree1 *) malloc(sizeof(tree1));
	temp->left = temp->right = NULL;
	temp->data = val;
	if(!(*tree2))
	{
		*tree2 = temp;
	}
	if(val <(*tree2)->data)
	{
		insert_tree(&(*tree2)->left,val);
	}

	else if(val > (*tree2)->data)
	{
		insert_tree(&(*tree2)->right,val);
	}
  }
	main()
	{
	int a,b;
//	printf(" %d ",sizeof(struct tree));
	 insert_tree(&root,4);
	 insert_tree(&root,3);
	 insert_tree(&root,5);
	 insert_tree(&root,9);
	 insert_tree(&root,15);
	 insert_tree(&root,6);

	 printf("preorder:");
	 preorder_tree(root);
	 mirror(root);
	 printf("preorder:");
	 preorder_tree(root);
	 a=size(root);
	 printf(" a= %d ",a);
	 b=depth(root);
	 printf(" depth=%d",b);
	 min_tree();
	}
