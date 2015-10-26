#include <stdio.h>
#include <stdlib.h>

int a[3][2] = {
	{100, 10},
	{500, 5},
	{1000, 5}
};

#define ROWS 3

typedef struct NODE

{
	char* s;
	struct NODE *next;
}node;
node *hlist[3]={NULL};

void mem_init()
{
	int i, size;
	char *p;

	for(i = 0; i < ROWS; i++)
	{
		size = (a[i][0] * a[i][1]);
		printf("size is : %d\n", size);

		p = malloc(size);

		init_free_pool(p, i);
	}

	display();
}

void init_free_pool(char *p, int i)
{
	int len = 0, j;

	for(j = 0; j < a[i][1]; j++)
	{
		add_free_buffer(p + len, a[i][0]);

		printf("P+LEN is : %d\n", p+len);

		len = len + a[i][0];
	}
}

int add_free_buffer(char *p, int size)
{
	int k = get_hash_key(size);
	node *new,*temp;

	new = malloc(sizeof(node));
	new->s = p;
	new->next = NULL;

	if(hlist[k] == NULL)
	{
		hlist[k] = new;
		return 0;
	}

	for(temp = hlist[k]; temp->next != NULL; temp = temp->next);
	temp->next = new;

	return 0;
}

int get_hash_key(int size)
{
#if 0
	if(size=a[0][0])
		return 0;
	else if(size=a[1][0])
		return 1;
	else if(size=a[2][0])
		return 2;
#endif
	int i,j;

	for(i = 0, j = 0; i < ROWS; i++, j++)
	{
		if(size == a[i][0])
		{
			printf("hkey returning K: %d\n",j);
			return j;
		}
	}
}

void display()
{
	node *t;
	int i;
	for(i=0;i<3;i++)
	{
		if(hlist[i]!=NULL)
		{
			t=hlist[i];
			for(t=hlist[i];t!=NULL;t=t->next)
			{
				printf("----->p : %u\n",t->s);
			}
			if(hlist[i]!=NULL)
				printf("\n");
		}
	}
}

main()
{
	mem_init();
}
