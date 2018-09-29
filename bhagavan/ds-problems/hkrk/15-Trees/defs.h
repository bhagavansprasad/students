typedef struct node_t
{
	struct node_t *left;
	struct node_t *right;
	int data;
}dlist_node; 

dlist_node * get_tree_header(void);
void recursive_printPostorder(dlist_node *node);
void recursive_printInorder(dlist_node* node);
void recursive_printPreorder(dlist_node* node);

void iterative_printPreorder(dlist_node *current);
void iterative_printInorder(dlist_node *node);
void iterative_printPostorder(dlist_node* node);

int delete_node_by_value(int n);

void push(void *p);
void * pop();
int is_stack_empty();
void init_stack();
