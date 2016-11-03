#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char p[100];
	struct node *next;
};
struct node *h[26]={NULL};
char
buff[25][100]={{"Amma"},{"avu"},{"Illu"},{"eega"},{"Vudata"},{"vuyala"},{"Rushi"},{"ruushi"},{"eluka"},{"enugu"},{"aushadam"},{"amruthatam"},{"aaha"}};
main()
{
	int i=0;
	for(i=0;i<12;i++)
	{
		add_node(buff[i]);
	}
	display();
}
int add_node(char *r)
{
	int hkey = 0;
	struct node *new,*t;
	hkey = gen_key(r);
	printf("key for %s == %d\n",r,hkey);
	new=(struct node*)malloc(sizeof(struct node));
	strcpy(new->p,r);
	new->next=NULL;
	if(h[hkey]==NULL)
	{
		h[hkey]=new;
		return 0;
	}
	for(t=h[hkey];t->next!=NULL;t=t->next);
		t->next=new;
		return 0;	
}
int gen_key(char *r)
{
	if(r[0]>=65 && r[0]<=90)
	{
		return r[0]-'A';
	}
	else if(r[0]>=97 && r[0]<=122)
	{
		return r[0]-'a';
	}
}
int display( )
{
	int i; 
	struct node *t;
	for(i = 0; i < 26; i++)
	{
		for(t=h[i];t!=NULL;t=t->next)
		{
			printf("in header[%d] nodes are === %s, \n",i,t->p);
		}
     }
}
