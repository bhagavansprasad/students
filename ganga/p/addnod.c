#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[10];
	struct node *next;
};
struct node *h[26]={NULL};
main()
{
	addnode("Anvitha");
	addnode("arun");
	addnode("ayesha");
	addnode("bharath");
	addnode("bhuvan");
	addnode("bhuvani");
	addnode("bharathi");
	addnode("zeeee");
    display();
}
int addnode(char *p)
{	
	int hkey;
	struct node *temp=NULL;
	struct node *ptr=NULL;
	ptr=malloc(sizeof(struct node));
	hkey=gen_hash_key(p);
	strcpy(ptr->name,p);
	ptr->next=NULL;
	if(h[hkey]==NULL)
	{
		h[hkey]=ptr;
		return 0;
	}
	for(temp=h[hkey];temp->next!=NULL;temp=temp->next);
	temp->next=ptr;
	return 0;
}
int gen_hash_key(char *p)
{
	int i=0;
	i=p[0];
	if((i>=65)&&(i<90))
	i=i-65;
	else
	i=i-97;
	return i;
}
int display()
{
struct node *temp=NULL;
	int i=0;
	for(i=0;i<26;i++)
	{
				//printf("%p",h[i]);
		for(temp=h[i];temp!=NULL;temp=temp->next)
		{
	//	if(h[i]!=NULL)
	//	{

	       printf("name=%s\t,add=%p",temp->name,temp);
		   printf("temp->next=%p\n",temp->next);
	//	}
	//	else
	//	break;
	printf("\n");
	}
      
	}
	return 0;
}



