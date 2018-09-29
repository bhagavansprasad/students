#include<stdio.h>
#include<stdlib.h>


struct data
{
	int val;
	struct data *next;
};

struct data *head=NULL;

int append(int n)
{
	struct data *temp,*new;
	new = malloc(sizeof(struct data));
	new->val = n;
	new->next=NULL;

	if(head == NULL)
	{
		head =new;
		return 0;
	}
	else
	{
		for(temp=head; temp->next!=NULL; temp=temp->next);
	temp->next = new;
	}
	
	}

void display()
{
printf("enter display\n");
	struct data *temp;
	for (temp = head ;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->val);
	}
	printf("\n");
}

void delete(int n)
{
	struct data *temp,*previous;
	for(temp=head;temp!=NULL;)
	{
		if(temp->val == n)
		{
			if(temp== head)
			{
				head = NULL;
				free(temp);
			}
			else
			{
				previous->next=temp->next;
				free(temp);
			}
		}

		else
		{
			previous=temp;
			temp=temp->next;
		}

	}
}

void appendfirst(int n)
{
	printf("ENTERED\n");
	struct data *temp,*new;
	temp=head;
	new=malloc(sizeof(struct data));
	new->val=n;
	new->next=temp;
	head=new;
}

void appendend(int n)
{
	printf("ENTERED\n");
	struct data *temp,*new;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	new=malloc(sizeof(struct data));
	new->val=n;
	temp->next=new;

	new->next=NULL;
	}

int append_any_pos(int n,int pos)
{
	struct data *temp,*new;
	int i;
	temp=head;
	for(i=1;i<pos;i++)
	 {
		printf("-------------------------->%d\n",temp->val);
		temp=temp->next;
		printf("-------------------------->%d\n",temp->val);
		if(temp->next == NULL)
		{
			printf("there are less than %d elements in list",pos);
			return 0;
		}
	}
	new=malloc(sizeof(struct data));
	new->val=n;
	new->next=temp->next;
	temp->next=new;

}


sort_nodes()
{
	struct data *temp,*new;
	int i,j,tempp;
	//new=malloc(sizeof(struct data));
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		for(new=temp->next;new->next!=NULL;new=new->next)
		{
			if((temp->val) > (new->val))
			{
				tempp=temp->val;
				temp->val=new->val;
				new->val=tempp;
			}
			
		}
	}
}

search_for_loop()
{
	struct data *temp,*new;
	int i,j,tempp;
	//new=malloc(sizeof(struct data));
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		for(new=temp->next;new->next!=NULL;new=new->next)
		{
			if((temp->next) == (new->next))
			{
		         printf("LIST IS LOOP\n");		
                       }
                       			
		}
	}
       printf("Not In Loop\n");
}


orderinsert(int data)
{
   struct data *temp,*prev;
   struct data *new = malloc(sizeof(struct data));
   temp = head;
   new -> val = data;
   new -> next = NULL;

   if(head == NULL)
   {
      head = new;
      return 0;
   }

   for(; temp != NULL; temp = temp -> next)
   {
      if(temp -> val >= data)
      {
         if(temp == head)
	 {
	   new->next = head;
	   head = new;
	   return 0;
	 }
	 else
	 {
	    new -> next = temp;
	    prev->next = new;
		 return 0;
	 }
	
      }
   }
   prev=temp;
   prev->next = new;
   return 0;
}

void reverse()
{
	struct data *temp,*pre;
	pre=NULL;
	temp=NULL;
	while(head!=NULL)
	{
		temp=head;
		head=temp->next;
		temp->next=pre;
		pre=temp;
	}
	head=temp;
}

int number_of_occurence(int data)
{
	struct data *temp;
	int count=0;
	temp=head;
	if(temp==NULL)
	{
		printf("No elements present in the list\n");
		return 0;
	}
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->val==data)
		{
			count++;
		}
	}
	printf("element =[ %d ]\t count=[%d]\n",data,count);
}
int middle_node()
{
	struct data *ptr1,*ptr2;
	ptr1=ptr2=head;
	int i=0;
	if(ptr1==NULL)
	{
		printf("no nodes present in the list\n");
		return 0;
	}
	while(ptr1->next!=NULL)
	{
		if(i==0)
		{
           ptr1=ptr1->next;
		   i=1;
		}
		else if(i==1)
		{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		i=0;
		}
	}
	printf("Middle Node is%d\n",ptr2->val);
	return 0;
}
main()
{
	/*	orderinsert(30);
		orderinsert(50);
		orderinsert(50);
		orderinsert(10);
		orderinsert(60);
		orderinsert(90);
		orderinsert(100);*/


	append(10);
	append(20);
	append(30);
	append(50);
	append(50);
	append(60);
	append(70);
	append(80);
	display();
	/*delete(40);
	  display();
	  delete(80);
	  display();
	  appendfirst(900);
	  display();
	  appendend(100);
	  display();
	  append_any_pos(1909,5);
	  display();
	//printf("entered sorting order\n");
	sort_nodes();
	display();
	reverse();
	display();
	//	search_for_loop();*/
	number_of_occurence(50);
	middle_node();

}



