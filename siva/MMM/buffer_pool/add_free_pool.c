#include "freebuffer5.h"
char buff[10][104];
 char buff1[15][474];
char buff2[5][254];
 char buff3[13][704];
char buff4[20][1504];

 node *head[5]={NULL};


void init_free_pool(void)
{

	int i;
	for(i=0;i<=9;i++)
	{
       int  *p=buff[i];
		*p=100;
		add_to_free_pool(buff[i],104);
	}
	for(i=0;i<=14;i++)
	{ 
	  int  *q=buff1[i];
		*q=470;
		add_to_free_pool(buff1[i],474);
	}
	for(i=0;i<=4;i++)
	{  
	  int  *k=buff2[i];
		*k=250;
		add_to_free_pool(buff2[i],254);
	}
	for(i=0;i<=12;i++)
	{ 
	 int   *j=buff3[i];
		*j=700;
		add_to_free_pool(buff3[i],704);
	}
	for(i=0;i<=19;i++)
	{ 
	   int  *n=buff4[i];
		*n=1500;
		add_to_free_pool(buff4[i],1504);
	}
}



int add_to_free_pool(char *b,int size)
{
	node *temp,*new;
	int hashkey;
	new=malloc(sizeof(node));
	new->fb=b;
	new->flag=1;
	hashkey=gen_hashkey(size);
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


char gen_hashkey(int size)
{
	if(size<=104)
	{
		return 0;
	}
	if(size>104 && size <=254)
	{
		return 2;
	}
	if(size>254 && size<=474)
	{
		return 1;
	}
	if(size>474 && size<=704)
	{
		return 3;
	}
	if(size>704 && size<=1504)
	{
		return 4;
	}
}


