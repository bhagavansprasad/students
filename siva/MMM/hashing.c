#include "hash_struct.h"

char gen_hashkey(char *b)
{
/*	if((b[0] <= 0 && b[0] <= 64) || (b[0]>=92 && b[0]<=96) ||b[0]>=102)
	{
		return ('Z'+1);
	}*/
	return(b[0]-((b[0]>='A' && b[0]<='Z')?'A':'a'));
}

int insert(char *b)
{
	node *temp,*new;
	int hashkey;
	new=malloc(sizeof(node));
	new->s=malloc((strlen(b))+1);
	hashkey=gen_hashkey(b);
	printf("%d\n",hashkey);
	if(head[hashkey] == NULL)
	{
		strcpy(new->s,b);
		new->next=NULL;
		head[hashkey]=new;
		return 0;
	}
	for(temp=head[hashkey];temp->next!=NULL;temp=temp->next);
	temp->next=new;
	strcpy(new->s,b);
	new->next!=NULL;
	return 0;
}

int afree(char *str)
{
	node *temp,*prev;
	int hashkey;
	hashkey=gen_hashkey(str);
	for(temp=head[hashkey];temp!=NULL;)
	{
		if(strcmp(temp->s,str)==0)
		{
			if(temp==head[hashkey])
			{
				head[hashkey]=temp->next;
				free(temp->s);
				free(temp);
				return 0;
			}
			else
			{
				prev->next=temp->next;
				free(temp->s);
				free(temp);
				return 0;
			}
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}

}


display()
{
	node *temp;
	int i;
	for(i=0;i<=26;i++)
	{
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
			printf("%s\t",temp->s);
		}
	}
	printf("\n");
}

main()
{
	insert("siva");
	insert("aura");
	insert("paidi");
	insert("tarun");
	insert("kumar");
	insert("ravi");
	insert("prem");
	insert("mohan");
	insert("hari");
//	afree("aura");
	display();
	printf("--------after display\n");
}
