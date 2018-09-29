#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct list
{
	char *ch;
	struct list *N;
};
struct list *h[26] ={NULL};
main()
{
	add_lst("abstract");
	add_lst("mind");
	add_lst("Bharath");
	add_lst("contineous");
	add_lst("amarnath");
	display();
}

int add_lst(char *str)
{
	struct list *p,*t;
	int k;
	k = hash_key(str);
	printf("k is : %d\n",k);
	p = malloc(sizeof(struct list));
	p->ch = malloc(strlen(str));
	strcpy(p->ch,str);
	printf("the p->ch valu is %s\n",p->ch);
	p->N = NULL;
	if(h[k] == NULL)
	{
		h[k] = p;
		return 0;
	}

	for (t = h[k];t->N != NULL;t = t->N);
	
		t->N = p;
		return 0;
	
}

int display()
{
	struct list *t;
	int k;
for(k=0;k<27;k++)
{
	for(t = h[k];t != NULL;t = t->N)
	{
		printf("the string is %s\n",t->ch);
		//printf("the string address is %u\n",t->ch);
	}
}	
}

int hash_key(char *str)
{
	if(str[0] >= 'A' && str[0] <= 'Z')
	return(str[0]-'A');
	else if(str[0] >= 'a' && str[0] <= 'z')
	return(str[0]-'a');
	else return 26;
	#if 0
	if('A' >= str[0] <= 'Z')
	return(str[0]-'A');
	else if('a' >= str[0] <='z')
	return(str[0]-'a');
	else
	return 26;
	#endif
}
