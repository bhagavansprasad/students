#include<stdio.h>
#include <sys/types.h>
#include <time.h>
#define ROWS 3
void* memory_creation();

void* populate_free_buff_list(char *p,int size,int val);

int addnode(char* p,int size);

int hashkeygen(int size);

void* amalloc(int size);

void display();

void afree(void *q);

char* current_time();

int get_pid(int *pid);

struct node
{
	int pid;
	time_t curr_time;
	int flag;
	void* add;
	struct node *link;
};


struct node *hlist[ROWS]={NULL,NULL,NULL};

struct header
{
	int h;
};


int memory[ROWS][2]={
	                    {100,2},
	                    {200,3},
	                    {300,5}
                        }; 
main()
{  char *r1,*r2,*r3;
   char *a;
   int pid;
	memory_creation();

	r1=amalloc(100);
	printf("r1 is %u\n",r1);
    sleep(1);


	r2=amalloc(100);
	printf("r2 is %u\n",r2);
    sleep(10);
	//afree(r1);
	//printf("r1 is %u\n",r1);
	r3=amalloc(200);
	printf("r3 is %u\n",r3);
	sleep(11);

	display();

}

/*for creating memory*/

void* memory_creation()
{
	int i=0,size=0,len=0;
	char *p;

	for(i=0;i<ROWS;i++)
	{
		size=size+((memory[i][0]+sizeof(struct header)+sizeof(struct node))*memory[i][1]);

		printf("size of header is %d\n",sizeof(struct header));

		printf("size of node is %d\n",sizeof(struct node));

		printf("size  of memory is %d\n",size);
	}

	p=malloc(size);

	for(i=0;i<ROWS;i++)
	{
		populate_free_buff_list(p+len,memory[i][0],memory[i][1]);

		len=len+(memory[i][0]+sizeof(struct node)+sizeof(struct header))*memory[i][1];
		printf("in memory creation the valude of len is %d\n",len);


	}

	printf("\n");

}

/*creating memory for same size of elments*/ 



void* populate_free_buff_list(char *p,int size,int val)
{

	int i,len=0;

	for(i=0;i<val;i++)
	{
		addnode(p+len,size);

		printf("size of header is %d\n",sizeof(struct header));

		printf("size of struct node is %d\n",sizeof(struct node));

		printf("in popualte free p val  is %u\n ",p+len+sizeof(struct node)+sizeof(struct header));

		len=len+size+sizeof(struct node)+sizeof(struct header);
	}

}

/*adding node*/


int addnode(char* p,int size)
{
	struct node *new,*temp;
	struct header *hv;
    int hl;
	hl=hashkeygen(size);

	hv=(struct node*)(p+sizeof(struct node));

	new=(struct node*)p;

	new->add=(void*)(p+sizeof(struct node)+sizeof(struct header));


	new->flag=0;

	new->link=NULL;

	hv->h=size;

	if(hlist[hl]==NULL)
	{
		hlist[hl]=new;
		return 0;
	}
	for(temp=hlist[hl];temp->link!=NULL;temp=temp->link);

	temp->link=new;	

}


/*generation of hashkey*/

int hashkeygen(int size)
{
	int i,k;

	for(i=0,k=0;i<ROWS;i++,k++)
	{
		if(size==memory[i][0])
		{
			printf("k value is %d\n ",k);
			return k;
		}
	}
}

/*allocation of memory*/


void* amalloc(int size)
{

    struct node *temp;
	int i,hn;
     
	 hn=hashkeygen(size);
	
	for(i=0;i<ROWS;i++)
	{
	   temp=hlist[hn];

       while(temp!=NULL)
	   {
           if(temp->flag==0)
		   {
		    temp->pid=getpid();
			time(&(temp->curr_time));
			ctime(&(temp->curr_time));
			printf("\n---->current time in amalloc%ld\n", temp->curr_time);
             temp->flag=1;
			 printf("the allocate memory is %u\n",temp->add);
			 return((void *)(temp->add));
		   }
         temp=temp->link;

	   }

	}
  return NULL;

}

/*freee function*/

void afree(void *q)
{
  struct node *temp;
   int *r,hr;

   r=q-sizeof(int);

    hr=hashkeygen(*r);

    temp=hlist[hr];
	

	while(temp!=NULL)
	{
      if(temp->add==q)
	  {
          temp->flag=0;
		  printf("temp->flag is %d\n",temp->flag);
	  }

	  temp=temp->link;
	}
}
/*get pid*/

int get_pid(int *pid)
{

return(getpid());
}

/*for display*/


void display()
{
	struct node *temp;
	int i=0;
	char buff[100];

	for(i=0;i<ROWS;i++)
	{
		if(hlist[i]!=NULL)

			temp=hlist[i];

		for(temp=hlist[i];temp!=NULL;temp=temp->link)
		{
			printf("hash list is %u\n",temp->add);
			strcpy(buff,ctime(&(temp->curr_time)));
			printf("current time is %s\n",buff);
			printf("pid value is %d\n",temp->pid);

		}
		printf("\n");

	}
}


