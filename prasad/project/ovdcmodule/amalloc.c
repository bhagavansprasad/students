#include"stdio.h"
#include"stdlib.h"
#include"time.h"
#include"signal.h"

struct data
{
    void *add;
    int time;
    struct data *next;
};
struct data *h=NULL;

int add_node(void *addr, int tim)
{
    struct *new,*temp;

    new=(struct data *)malloc(sizeof(struct data));
    new->add=addr;
    new->time=tim;
    new->next=NULL;

    if(h==NULL)
    {
	h=new;
	return 0;
    }

    //TODO : Add at begining of the list
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

int delete_node(void *ptr)
{
    struct data *temp, *prev;
    temp=prev=h;

    if(h->add==ptr)
    {
	h=temp->next;
	free(temp);
	free(ptr);
	return 0;
    }

    for(temp,prev; temp!=NULL; prev=temp,temp=temp->next)
    {
	if(temp->add==ptr)
	{
	    prev->next=temp->next;
	    free(temp);
	    free(ptr);
	    return 0;
	}
    }
    printf("%u node with this address is not present in the list\n");
}

int afree(void *ptr)
{
    if(h==NULL)
    {
	printf("there are no nodes to delete\n");
	return 0;
    }
    delete_node(ptr);
}


display()
{
    for(temp=h;temp!=NULL;temp=temp->next)
	printf("add=%u  time=%d  \n",temp->add,temp->time);
}

int cml()
{
    time_t tim;
    int ctime;
    printf("current time=%d\n",tim);
    printf("the cml function called\n");	
    for(temp=h; temp!=NULL; temp=temp->next)
    {

	printf("creation time=%d\n",temp->tme);
	ctime=(tim)-(temp->time);

	printf("ctime=%d\n",ctime);
	if(ctime>10)
	    afree(temp->add);
	display();
	printf("10secs before allocated node is freed\n");
    }
    sleep(2);
    cml();
}

sighandle()
{
    signal(SIGALRM,cml);
    alarm(5);
    pause();

    //display();

}

main()
{
    void *t1,*t2,*t3;

    t1=amalloc(10);
    printf("%u \n",t1);
    sleep(2);
    t2=amalloc(20);
    printf("%u \n",t2);
    sleep(2);
    t3=amalloc(20);
    printf("%u \n",t3);
    afree(t1);
    display();
    sighandle();

}
