#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int addnode(char *s);
void display(int i);
//int gen_key(char *s);


struct node
{
	char word[200];
	struct node *link;
};
