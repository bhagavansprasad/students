#include "structure.h"

extern struct node *h[26];

int addnode(char *s)
{
	struct node *new, *temp;
	int key;

	key = gen_key(s);

	printf("-->adding :%s, key :%d\n", s, key);


	new = (struct node *)malloc(sizeof(struct node));
	strcpy(new->word, s);
	new->link = NULL;

	if(h[key] == NULL)
	{
		h[key] = new;

		return 0;
	}

	temp = h[key];
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	temp -> link = new;
	return 0;
}

void dump_list(void)
{
	struct node *temp;
	int key = 0, flag = 1, count = 0;

	for (key = 0; key < 26; key++)
	{
		if (flag)
		{
			printf("--%d", count);
			printf("\n");
			printf("%d. ", key);
			flag = 0;
			count = 0;
		}

		temp = h[key];
		while(temp != NULL)
		{
			printf("%15s", temp->word);
			temp = temp->link;
			count++;

			flag = 1;
		}

	}

	printf("\n");
	return;
}

