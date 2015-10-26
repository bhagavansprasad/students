#include<stdio.h>
int adding(int n);
struct student
{
	int data;
	struct student *next;
};
struct student *head=NULL;
main()
{
	adding(50);
	adding(40);
	adding(30);
	adding(20);
	adding(15);
	display();
	finding_order(&head);
}
finding_order(struct student *head)
{
	struct student *temp,*next;
	int i;
	temp=head;
	next=temp->next;
	while(1)
	{
		if(temp->data <= next->data)
		{
			i=(next->data) - (temp->data);
			if(i>=1)
			{
				temp=temp->next;
				next=next->next;
			}
			if(temp == head)
			{
				printf("Ascending Order\n");
				exit(1);
			}


		}
	
	}
		printf("AFTER WHILE LOOP\n");


}

int adding(int n)
{
	struct student *temp,*new;
	new = malloc(sizeof(struct student));
	new->data=n;
	if(head == NULL)
	{
		head=new;
		new->next=head;
		return 0;
	}
	for(temp=head;temp->next!=head;temp=temp->next);
	temp->next=new;

	new->next=head;
	
}
display()
{
	printf("dispaly loop\n");

	struct student *temp;
	temp=head;
	if(temp == head)
	{
		printf("%d\t",temp->data);

		}
		temp=temp->next;

	while(temp!=head)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

search_for_loop()
{
	struct student *temp,*new;
	int i,j,tempp;
	//new=malloc(sizeof(struct data));
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		for(new=temp->next;new->next!=NULL;new=new->next)
		{
			if((temp->next) == (new->next))
			{
		         printf("LIST IS LOOP\n");
                         return 0;		
                       }
                       			
		}
	}
       printf("Not In Loop\n");
}

