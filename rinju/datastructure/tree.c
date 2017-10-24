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
	if(!tree2)	{
		return;
	}
	printf("  %d ",tree2->data);
	preorder_tree(tree2->left);
	preorder_tree(tree2->right);
}
void inorder_tree(tree1 *tree2)
{
	if(!tree2)	{
		return;
	}
	inorder_tree(tree2->left);
	printf(" %d ",tree2->data);
	inorder_tree(tree2->right);
}
void postorder_tree(tree1 *tree2)
{
	if(!tree2)	{
		return;
	}
	postorder_tree(tree2->left);
	postorder_tree(tree2->right);
	printf(" %d ",tree2->data);
}
int element_tree(tree1 *tree2)
{
	if(!tree2)	{
		return 0;
	}
	return (element_tree(tree2->left) + element_tree(tree2->right) + 1);
}
void insert_tree(tree1 **tree2 , int val)
  {
    tree1 *temp = NULL;
	temp = malloc(sizeof(tree1));
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
	int c = 0;
	insert_tree(&root,4);
	insert_tree(&root,3);
	insert_tree(&root,5);
	printf("preorder:");
	preorder_tree(root);
	printf("\ninorder:");
	inorder_tree(root);
	printf("\npostorder:");
	postorder_tree(root);
	c = element_tree(root); 
	printf(" element =%d",c);
}
