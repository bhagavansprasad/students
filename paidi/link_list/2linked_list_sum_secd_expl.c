#include <stdio.h>
#include <stdlib.h>
void display(int list);

typedef struct _node
{
	int data;
	struct _node *next;
}node;

node *head[3] = {NULL,NULL,NULL};

int addnode(int x, int i)
{
	node *temp,*new;
	new = malloc(sizeof(node));
	new->data = x;
	new->next = head[i];
	head[i] = new;
}
int  add1(int num,int list)
{
	int a,i;
	printf("num1---%d\n",num);
	while(num != 0)
	{
		a = num % 10;
//	printf(" a---%d\n",a);
		addnode(a,list);
		num = num/10;
		if(num == 0)
		{
		 for(i=0;i<2;i++)
		 addnode(0,list);
		}
		 
	 }
}

int  add(int num,int list)
{
	int a,i;
	printf(" num2---%d\n",num);
	while(num != 0)
	{
		a = num % 10;
	//	printf(" a---%d\n",a);
		addnode(a,list);
		num = num/10;
	/*	if(num == 0)
		{
		 for(i=0;i<2;i++)
		   addnode(0,list);
		}
	*/	 
	 }
}

int all_nodes_sum()
{
	node *temp1 = NULL,*temp2 = NULL,*temp3 = NULL,*temp4 = NULL;
	int val = 0,num = 0,sum = 0, a = 0,b = 0,c= 0;

	head[2] = NULL;

	for(;temp1 != head[0] && temp2 != head[1];)
	{
		for(temp1 = head[0]; temp1->next!= temp3; temp1 = temp1->next);
			temp3 = temp1;
		for(temp2 = head[1]; temp2->next!= temp4; temp2 = temp2->next);
			temp4 = temp2;
		//	printf("temp3->data:%d--->temp4->data:%d\n",temp3->data,temp4->data);
		val = temp3->data + temp4->data + sum;
		//printf("value%d\n",val);
		num = val % 10;
		addnode(num,2);
		sum = val/10;
		//printf("sum %d\n",sum);

	}

}
void display(int list)
{
	node *temp;
	temp = head[list];
	while(temp!=NULL)
	{
		printf("|%d|-->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

main()
{
	add(1234, 0);
	display(0);
	add1(98, 1);
	display(1);
	all_nodes_sum();
	display(2);
}
