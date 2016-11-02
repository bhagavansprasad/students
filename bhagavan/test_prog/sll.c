struct data
{
	int value;
	struct data *next;
};

struct data *h = NULL;

main()
{
	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);

	dump_list();
}


int add_node(int n)
{
	struct data *ptr = NULL;
	struct data *temp = NULL;

	ptr = malloc(sizeof(struct data));
	ptr->value = n;
	ptr->next = NULL;

	if (h == NULL)
	{
		h = ptr;
		return 0;
	}

	for (temp = h; temp -> next != NULL; temp = temp->next)
	{
	}

	temp->next = ptr;

	return 0;
}


int dump_list(void)
{
	struct data *temp = NULL;

	temp = h;

	while(temp != NULL)
	{
		printf("%d\n", temp->value);

		temp = temp -> next;
	}

	return 0;
}






