#include<stdio.h>
int creat_hashtable(void*);
int generate_key(void*);
void display();
struct node
{
	int flag;
	void *b;
	struct node *a;
};
struct node *h[3]={NULL,NULL,NULL};
void *p1[10];

main()
{
	int size=0,i;
	char *p;
	//char *p1[10];
	int buff[3][2]={  {100,2},
		{200,3},
		{300,5}};
	for(i=0;i<3;i++)
	{
		size=size+buff[i][0]*buff[i][1];
	}
	printf("Size :%d\n",size);
	p=(char*)malloc(size);

	printf("Size of P :%p\n",p);

	p1[0]=p;
	p1[1]=&p[100];
	p1[2]=&p[200];
	p1[3]=&p[400];
	p1[4]=&p[600];
	p1[5]=&p[900];
	p1[6]=&p[1200];
	p1[7]=&p[1500];
	p1[8]=&p[1800];
	p1[9]=&p[2100];
	for(i=0;i<10;i++)
	{
		printf("print the address of p is p[%d]\n%p",i, p[i]);
		creat_hashtable(p1[i]);
	}
	printf("\ndispalying the list using display()\n");
	 display();
}



int creat_hashtable(void* x)
{
	int k;
	struct node *t;
	struct node *temp;

	t=malloc(sizeof(struct node));
	t->flag=0;
	t->b=x;
	t->a=NULL;

	k=generate_key(x);
	if(h[k]==NULL)
	{
		h[k]=t;
		return 0;
	}
	temp=h[k];
	while(temp->a!=NULL)
		temp=temp->a;
	temp->a = t;
	return 0;
}




int generate_key(void* y)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(y==p1[i])
		{ 
			if(i>=0 && i<=1)
			{
				printf("print the address of p is p[%d]\n%p",i, p1[i]);
				return 0;
			}
			else if(i>=2 && i<=4)
			{
				printf("print the address of p is p[%d]\n%p",i, p1[i]);
				return 1;
			}
			else
			{
				printf("print the address of p is p[%d]\n%p",i, p1[i]);
				return 2;
			}
		}
	}
}




void display()
{
	int i;
	struct node *temp;
	for(i=0;i<3;i++)
	{
		temp=h[i];
		while(temp!=NULL)
		{
			printf("%p\n",temp->b);
			temp=temp->a;
		}
		printf("\n\a");
	}
}
