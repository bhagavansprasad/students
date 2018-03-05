#include "stdio.h"
#include "stdlib.h"
#include "defs.h"

dlist_node *h = NULL;

//int values[] = {10, 8, 9, 6, 12, 18, 15};
int values[] = {12, 5, 15, 3, 7, 13, 17, 1, 9, 14, 20, 8, 11, 18, 25, 19, 24, 26, 22, 23};

int add_node_btree(int n)
{
    dlist_node *new = (dlist_node *)malloc(sizeof(dlist_node));
    dlist_node **temp = &h;
    new->left = new->right = NULL;
    new->data = n;

    if (*temp == NULL)
    {
        *temp = new; 
        return 0;
    }

    while(*temp != NULL)
    {
        if (n <= (*temp)->data)
            temp = &((*temp)->left);
        else
            temp = &((*temp)->right);
    }
    *temp = new;
    return 1;
}

dlist_node * get_tree_header(void)
{
    return h;
}

void dump_btree_recrusive(void)
{
    printf("\nPreOrder  recursive :");
    recursive_printPreorder(h);

    printf("\nInOrder   recursive :");
    recursive_printInorder(h);

    printf("\nPostOrder recursive :");
    recursive_printPostorder(h);

    printf("\n");
}

void dump_btree_non_recrusive(void)
{
    #if 0
    printf("\nPostOrder           :");
    printPostorder(h);
    printf("\n");
    return;
    #endif

    printf("\nPreOrder  iterative :");
    iterative_printPreorder(h);
    printf("\n");

    printf("\nInOrder   iterative :");
    iterative_printInorder(h);

    //printf("\nPostOrder iterative :");
    //iterative_printPostorder(h);

    printf("\n");
}

void dump_iterative_preorder(void)
{
    printf("\nPreOrder  iterative :");
    iterative_printPreorder(h);
}

void test_delete_node(void)
{
    //dump_iterative_preorder();
    //delete_node_by_value(11);
    //dump_iterative_preorder();
    //delete_node_by_value(8);
    //delete_node_by_value(13);
    delete_node_by_value(20);
    dump_iterative_preorder();

}

int main()
{
    int i = 0;

    for (i = 0; i < sizeof(values)/sizeof(int); i++)
        add_node_btree(values[i]);

    //dump_btree_recrusive();
    //dump_btree_non_recrusive();

    printf("\nPreOrder  iterative :");
    iterative_printPreorder(h);
    printf("\n");

    test_delete_node();

    printf("\nPreOrder  iterative :");
    iterative_printPreorder(h);
    printf("\n");
#if 0 
#endif
    return 0;
}
