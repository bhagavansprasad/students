#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

void recursive_printPreorder(dlist_node* node)
{
    if (node == NULL)
         return;
 
    printf("%5d", node->data);
 
    recursive_printPreorder(node->left);  
 
    recursive_printPreorder(node->right);
} 

void recursive_printInorder(dlist_node* node)
{
    if (node == NULL)
          return;
 
    recursive_printInorder(node->left);
 
    printf("%5d", node->data);
 
    recursive_printInorder(node->right);
}
 
void recursive_printPostorder(dlist_node *node)
{
    if (node == NULL)
       return;
 
    recursive_printPostorder(node->left);

    recursive_printPostorder(node->right);

    printf("%5d", node->data);
}
 
void iterative_printPreorder(dlist_node *current)
{
    init_stack();
    push(current);
    while (!is_stack_empty())
    {
        current = pop();
        printf("%5d", current->data);

        if (current->right != NULL)
            push(current->right);

        if (current->left != NULL)
            push(current->left);
    }
    init_stack();
}

void iterative_printInorder(dlist_node *node)
{
    dlist_node *current = node;
    int done = 1;
    init_stack();

    while(done)
    {
        if (current != NULL)
        {
            push(current);
            current = current->left;
        }
        else
        {
            if (is_stack_empty() == 0)
            {
                current = pop();
                printf("%5d", current->data);
                current = current->right;
            }
            else
            {
                done = 0;
            }
        }
    }
    init_stack();
}

void iterative_printPostorder(dlist_node* node)
{
    dlist_node *current = node;
    int done = 1;
    init_stack();

    while(done)
    {
        if(current != NULL)
        {
            push(current);
            current = current->left;
        }
        else
        {
            if (is_stack_empty() == 0)
            {
                current = pop();
                current = current->right;
                if (current->right == NULL)
                    printf("%5d", current->data);
            }
            else
                done = 0;
        }
    }
    init_stack();
}

int get_min_value(int n, dlist_node *node)
{
    while(node->left != NULL)
    {
        node = node->left;
    }

    return 0;
}

int delete_node_by_value(int n)
{
    dlist_node *current = get_tree_header();
    dlist_node *prev_node = NULL;
    dlist_node *temp = NULL;

    init_stack();
    while(1)
    {
        printf("%5d\n", current->data);
        if (current->data == n)
        {
            if (current-> left == NULL && current->right == NULL)
            {
                prev_node = pop();
                if (prev_node->left == current)
                    prev_node->left = NULL;
                else
                    prev_node->right = NULL;
                free(current);
                init_stack();
                return 0;
            }
            else if (current-> left != NULL && current->right == NULL)
            {
                current->data = current->left->data;
                temp = current->left;
                current->left = temp->left;
                current->right = temp->right;
                free(temp);
                init_stack();
                return 0;
            }
            else if (current-> left == NULL && current->right != NULL)
            {
                current->data = current->right->data;
                temp = current->right;
                current->left = temp->left;
                current->right = temp->right;
                free(temp);
                init_stack();
                return 0;
            }
            else
            {
                temp = current->right;

                //node minimum right subtree
                while(temp->left != NULL)
                {
                    push(temp);
                    temp = temp->left;
                }
                current->data = temp->data;
                n = current->data;
                current = temp;
                continue;
            }
        }

        push(current);

        if (n < current->data)
            current = current->left;
        else
            current = current->right;
    }
    init_stack();
}

