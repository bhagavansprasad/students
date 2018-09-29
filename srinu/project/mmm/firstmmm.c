#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROWS 3

struct node
{
	int pid;
	int flag;
	 time_t t;
	void *s;
	struct node *link;
};

struct header
{
	int hs;
};

struct node *hlist[ROWS]={NULL};

int mem_req[ROWS][2]={
	{100,2},
	{200,3},
	{300,4}
};

int hashkeygen(int size)
{
	int i,k; 

	for(i=0 ,k=0; i<ROWS; i++, k++)
	{
		if(size == mem_req[i][0])
		{
			printf("val is %d\n",k);

			return k;
		}
	}
}

void display()
{
	struct node *temp;
	int i;

	for(i=0; i<ROWS; i++)
	{
		if( hlist[i]!=NULL )
		{
			temp = hlist[i];
				
			char buff[100];
				temp->pid=get_pid();
				//time(&(temp->t));
		//		ctime(&(temp->t));
			//	printf("the temp->pid value is %ld\n",temp->pid);
			//	printf("the value of time is %d\n",temp->t);
				strcpy(buff,ctime(&(temp->t)));
				//printf("ctime :%s\n",ctime(&t));
				printf("the value of buff is %s\n",buff);
			
			for( temp = hlist[i]; temp!=NULL; temp= temp->link)
				printf("%p\n",temp->s);

			printf("\n");
		}
	}
}

void* amalloc(int size)
{
	int i;
	time_t t1;
	struct node *temp;
	int hn=hashkeygen(size);

	for(i=0;i<ROWS;i++)
	{
		temp=hlist[hn];

		while(temp != NULL)
		{
			if(temp->flag==0)
			{
				temp->flag=1;
				temp->pid=get_pid();
				time(&(temp->t));
				ctime(&(temp->t));
				printf("the value of temp->time is %ld\n",temp->t);
				printf("the value of temp->pid is %d\n",temp->pid);

				printf("--->address before return is %p\n", temp->s);

				return ((void *)temp->s);
			}

			temp = temp->link;
		}
	}
	return NULL;
}
int get_pid(void)
{
	return get_pid;
}

void afree(void *p)
{
	struct node *temp;
	//int i;
	
	int *val=p-sizeof(struct header);
	printf("the value of val is %d\n",*val);
	int key=hashkeygen(*val);
	//for(i = 0; i < ROWS; i++)
	
		temp = hlist[key];
		
		while(temp!=NULL)
		{
			
			if(temp->s == p)
			{
					temp->flag=0;
			}
			
			temp=temp->link;
		}
}


void *addnode(char *p, int size)
{
	int hkey;
	struct node  *new, *temp;
	struct header *hv;

	hkey = hashkeygen(size);

	hv=(struct node *)(p + sizeof( struct node ));
	new =(struct node *)p;
	new->s =(void*)( p+sizeof(struct node ) + sizeof(struct header));
	new->flag=0;
	new->link = NULL;
	hv->hs=size;

	printf("the size of each node is %d\n",hv->hs);

	if(hlist[hkey]==NULL)
	{
		hlist[hkey] = new;
		return 0;
	}

	for(temp = hlist[hkey];temp->link!= NULL;temp = temp->link);

	temp->link = new;
}

void *populate_free_buff_list( char *p, int buff_len, int nob)
{
	int i,len=0;

	for( i = 0; i < nob; i++)
	{
		addnode(p+len, buff_len);

		printf("size of header is %lu\n",sizeof(struct header));
		printf("size of struct node is %lu\n",sizeof(struct node));
		printf ("p val is  :%p\n" ,p+len+sizeof(struct node)+sizeof(struct header)) ;

		len = len + buff_len + sizeof(struct node) + sizeof(struct header);
	}
}

void *memory_creation()
{
	int i, size=0, len=0;
	char *p;

	for(i=0 ; i < ROWS; i++)
		size = size + ( (mem_req[i][0] + sizeof(struct node) + sizeof(struct header)) * mem_req[i][1]);

	printf("sizeof structure is %lu\n",sizeof( struct node ));
	printf("size of header is   %lu\n",sizeof( struct header ));
	printf("size is             %d\n",size);

	p = malloc(size);

	for(i = 0; i < ROWS; i++ )
	{
		populate_free_buff_list ( p+len, mem_req[i][0], mem_req[i][1] );

		len = len + (( mem_req[i][0] + sizeof(struct node) + sizeof(struct header)) * mem_req[i][1]);
	}

	printf("the value of len is %d\n",len);

	printf("\n");

}


main()
{
	char *q1,*q2;
	char *q3;

	memory_creation();

	q1=amalloc(100);
	printf("the value of amlloc is %p\n",q1);
	sleep(2);

	q2=amalloc(100);
	printf("the value of q2 amlloc is %p\n",q2);
	sleep(2);
	afree(q2);

	q3 = amalloc(100);
	printf("the value of q3 amlloc is %p\n",q3);

	display();
}


#if 0
	/*struct header *hv;
	hv=(struct header *)((char *)p-sizeof(struct header));
	
	printf("the value of hv is %p\n",hv);
	printf("the size of struct_header is :%lu\n",sizeof(struct header));
	printf("the size of hv->hs is %d\n",hv->hs);
	
	temp=(struct node *)(*((int *)p-1));
	
	printf("the size of temp value is %d\n",temp);
	printf("before freezing the value of temp->flag is %d\n",temp->flag);
	
	temp->flag=0;
	printf("buffer freezing is %d\n",hv->hs);
	int hr=hashkeygen(hr->hs);*/
	
#endif
