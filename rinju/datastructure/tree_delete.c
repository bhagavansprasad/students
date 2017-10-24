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
tree1* search(tree1 **tree2,int val)
{
	tree1 *temp = *tree2;
	if(!(*tree2))
		printf("no element\n");

	if(val == temp->data)
	{
		return temp;
	}
    else if(val < temp->data)
	{
	  search(&(temp->left),val);
	}
	 
	 else if(val > temp->data)
	 {
	 search(&(temp->right),val);
	 }

 }

void delete(tree1 *tree2)
{
if(tree2)
{
delete(tree2->left);
delete(tree2->right);
free(tree2);
}
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
	tree1 *tmp = NULL;
	insert_tree(&root,4);
	insert_tree(&root,3);
	insert_tree(&root,5);

	printf("preorder:");
	preorder_tree(root);
	tmp=search(&root,3);
	if(tmp)
		printf(" search element =%d",tmp->data);
delete(root);
	printf("preorder:");
	preorder_tree(root);
	}
