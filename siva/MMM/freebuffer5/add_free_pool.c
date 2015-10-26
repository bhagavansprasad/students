#include "freebuffer5.h"
char buff[10][100];
 char buff1[15][470];
char buff2[5][250];
 char buff3[13][700];
char buff4[20][1500];

int add_to_free_pool(char *b,int size)
{
	node *temp,*new;
	int hashkey;
	new=malloc(sizeof(node));
	new->fb=b;
	new->flag=1;
	hashkey=gen_hashkey(size);
	printf("%d\n",hashkey);
	if(head[hashkey] == NULL)
	{
		new->next=NULL;
		head[hashkey]=new;
		return 0;
	}
	for(temp=head[hashkey];temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->next!=NULL;
	return 0;
}

display()
{
	node *temp;
	int i;
	for(i=0;i<=26;i++)
	{
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
			printf("%s\t",temp->fb);
		}
	}
	printf("\n");
}

char gen_hashkey(int size)
{
	if(size<=100)
	{
		return 0;
	}
	if(size>=100 && size <=250)
	{
		return 2;
	}
	if(size>=250 && size<=470)
	{
		return 1;
	}
	if(size>=470 && size<=700)
	{
		return 3;
	}
	if(size>=700 && size<=1500)
	{
		return 4;
	}
	printf("Generating Hashkey Failed: \n");
}

void init_free_pool(void)
{
	int i;
	for(i=0;i<=9;i++)
	{
		add_to_free_pool(buff[i],100);
	}
	for(i=0;i<=14;i++)
	{
		add_to_free_pool(buff1[i],100);
	}
	for(i=0;i<=4;i++)
	{
		add_to_free_pool(buff2[i],100);
	}
	for(i=0;i<=12;i++)
	{
		add_to_free_pool(buff3[i],100);
	}
	for(i=0;i<=19;i++)
	{
		add_to_free_pool(buff4[i],100);
	}
}



