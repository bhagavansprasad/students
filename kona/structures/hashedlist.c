#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASH_SIZE 30 
int addnode(char *);
int hashkeygen(char *);
void display();
struct node
{
	char *p;
	struct node *link;
};
struct node *hlist[HASH_SIZE]={NULL};
char
*buf[]={"a-Alluarjun","b-BALAKRISHNA BRAND","C-chiranjivi","d-danush","E-elizibith","f-father","g-gopichandh","h-hruthik","i-ileyana","j-johnabraham","k-KALYANRAM","l-lovely","M-Mahesh","n-NTR","o-omkarannaiah","p-POWERSTAR PAWANKALYAN","q-queen","r-Ramcharan","s-SREENIVASULAREDDY","t-Tharun","u-Udhaykiran","v-VENKATESAMAIAH","w-Wonderla","x-Xman","y-YUGESHNAIDU","z-zebra","8885823243","aishwarya"};
main()
{
	int i;
	for(i = 0; i < (sizeof(buf)/sizeof(char *)); i++)
	{
		addnode(buf[i]);
	}
	display();
}
int addnode(char *q)
{
	int hl;
	struct node *new,*temp;
	new=malloc(sizeof(struct node));
	new->p=malloc(strlen(q)+1);
	new->link=NULL;
	strcpy(new->p,q);
	hl=hashkeygen(q);
	if(hlist[hl]==NULL)
	{
		hlist[hl]=new;
		return 0;
	}
	for(temp=hlist[hl];temp->link!=NULL;temp=temp->link);
	temp->link=new;
}
int hashkeygen(char *q)
{
	if(q[0]>='A' && q[0]<='Z')
		return(q[0]-'A');
	else if(q[0] >= 'a' && q[0] <= 'z')
		return (q[0]-'a');
	else
		return HASH_SIZE-1;
}
void display()
{
	struct node *t;
	int i;
	for(i=0;i<=HASH_SIZE;i++)
	{
		if(hlist[i]!=NULL)
		{
			t=hlist[i];
			printf("%c are----->",i+65);
			for(t=hlist[i];t!=NULL;t=t->link)
			{
				printf("%s",t->p);
			}
			//if(hlist[i]!=NULL)
			printf("\n");
		}
	}
}
