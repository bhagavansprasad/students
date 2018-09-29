#include"stdio.h"
#include"stdlib.h"
#include"time.h"
struct data
{
	void *add;
	int time;
	struct data *next;
};
struct data *h=NULL,*new,*temp;

add_node(void *addr,int tim)
{
	new=(struct data *)malloc(sizeof(struct data));
	new->add=addr;
	new->time=tim;
	new->next=NULL;

	if(h==NULL)
	{
		h=new;
		return 0;
	}

	for(temp=h; temp->next!=NULL; temp=temp->next);
	temp->next=new;
	return 0;
}

void *amalloc(int size)
{
	void *t;
	time_t tim;
	tim=time(NULL);

	t=malloc(size);

	add_node(t,tim);
	return t;
}

display()
{
	for(temp=h;temp!=NULL;temp=temp->next)
		printf("add=%u  time=%d  \n",temp->add,temp->time);
}

main()
{

	void *t1;
	t1=amalloc(10);
	printf("%u \n",t1);
	sleep(2);
	t1=amalloc(20);
	printf("%u \n",t1);
	display();
}
