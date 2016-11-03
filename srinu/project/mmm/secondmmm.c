#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define ROWS 3
#define UNIQUE_STRING "@#$&*"
#define ANOTHER 3

 int peak=0,b=0;
 int hn;
 int key;
int hkey;
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
typedef struct buffer_tail_t
{
	char uniq_str[10];
}buffer_tail;
typedef struct hash_fields
{
	int *h;
	int total;
	int peak_usage;
	int allocated;
	int avilable_buffs;
	int total_frees;
	int malloc_missing;
}buff_pool;
buff_pool fields[3]={
					{NULL,0,0,0,0,0,0},
					{NULL,0,0,0,0,0,0},
					{NULL,0,0,0,0,0,0}
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
			printf("----->val is %d\n",k);

			return k;
		}
	}
}
void display_data()
{
	int i;
	for(i=0;i<ROWS;i++)
	{
		printf("----->the value of fields[%d].total is            %d\n",i,fields[i].total);
		printf("----->the value of fields[%d].peak_usage is       %d\n",i,fields[i].peak_usage);
		printf("----->the value of fields[%d].allocated is        %d\n",i,fields[i].allocated);
		printf("----->the value of fields[%d].avilable_buffs is	  %d\n",i,fields[i].avilable_buffs);
		printf("----->the value of fields[%d].malloc_missing is   %d\n",i,fields[i].malloc_missing);
		printf("----->the value of fields[%d].total_frees is      %d\n",i,fields[i].total_frees);
	}
}
void display()
{
	struct node *temp;
	int i;
	//printf("  node        struct_node     header      pid     time\n");
	for(i=0; i<ROWS; i++)
	{
		if( fields[i].h!=NULL )
		{
			temp = fields[i].h;
				
			   char buff[100];
				temp->pid=get_pid();
				strcpy(buff,ctime(&(temp->t)));
				#if 0
				printf("%p\t",temp);
				printf("%p\t",temp->link);
				printf("%d\t",temp->pid);
				printf("%d\t",temp->t);
				printf("%s\t",buff);
				#endif
				

				printf("------->the value of buff is %s\n",buff);
			
			for( temp = fields[i].h; temp!=NULL; temp= temp->link)
				printf("----->%p\n",temp->s);

			printf("\n");
		}
	}
}
void* amalloc(int size)
{
	int i;
	time_t t1;
	struct node *temp;
	hn=hashkeygen(size);
	
	for(i=0;i<ROWS;i++)
	{
		temp=fields[hn].h;

		while(temp != NULL)
		{
			if(temp->flag==0)
			{
				b++;
			
				if(peak<=b)
				{
					peak=b;
					fields[hn].peak_usage=peak;
				}
				temp->flag=1;
				fields[hn].allocated++;
				fields[hn].avilable_buffs=fields[hn].total-fields[hn].allocated;
				temp->pid=get_pid();
				time(&(temp->t));
				ctime(&(temp->t));
				printf("------>the value of temp->time is %ld\n",temp->t);
				printf("------->the value of temp->pid is %d\n",temp->pid);

				printf("--->address before return is %p\n", temp->s);

				return ((void *)temp->s);
			}

			temp = temp->link;
		}
	}
	fields[hn].malloc_missing++;
	return NULL;
}
int get_pid(void)
{
	return get_pid;
}

void afree(void *p)
{
	int a;
	struct node *temp;
	struct header *bh=(struct header *)((void *)p-sizeof(struct header));
	printf("-------->the bh value is------>%d\n",bh->hs);
	//int *val=p-sizeof(struct header);
//	printf("------->the value of val is %d\n",*val);
	//int key=hashkeygen(*val);
	key=hashkeygen(bh->hs);
	buffer_tail *bt=(buffer_tail *)((char *)p+(bh->hs));
	printf("--->the value of tail in afree is %s\n",(char *)bt);
		
		a=memcmp(bt,UNIQUE_STRING,5);
		if(a!=0)
		{
			printf("======>buffer overflow will occured<=====\n");
		}
		temp = fields[key].h;
		
		while(temp!=NULL)
		{
			
			if(temp->s == p)
			{
					temp->flag=0;
					b=0;
					fields[key].allocated--;
					fields[key].total_frees++;
			}
			
			temp=temp->link;
		}
}


void *addnode(char *p, int size)
{
	struct node  *new, *temp;
	struct header *hv;
	buffer_tail *bt;
	hkey = hashkeygen(size);

	hv=(struct node *)(p + sizeof( struct node ));
	bt=(buffer_tail *)(p+sizeof(struct node)+sizeof(struct header)+size);
	new =(struct node *)p;
	new->s =(void*)( p+sizeof(struct node ) + sizeof(struct header));
	new->flag=0;
	new->link = NULL;
	hv->hs=size;
	strcpy(bt->uniq_str,UNIQUE_STRING);
	printf("---->the value of tail is--->%s\n",(char *)bt);
	printf("----->the actual value of p is %p\n",new->s);
	printf("------>the size of each node is %d\n",hv->hs);

	if(fields[hkey].h==NULL)
	{
		fields[hkey].h = new;
		fields[hkey].total++;

		return 0;
	}

	for(temp = fields[hkey].h;temp->link!= NULL;temp = temp->link);

	temp->link = new;
		fields[hkey].total++;
		return 0;

}

void *populate_free_buff_list( char *p, int buff_len, int nob)
{
	int i,len=0;

	for( i = 0; i < nob; i++)
	{
		addnode(p+len, buff_len);

		printf("------>size of header is %lu\n",sizeof(struct header));
		printf("------>size of struct node is %lu\n",sizeof(struct node));
		printf("------>size of tail is %lu\n",sizeof(buffer_tail));
		printf ("----->p val is  :%p\n" ,p+len+sizeof(struct node)+sizeof(struct header)+sizeof(buffer_tail)) ;

		len = len + buff_len + sizeof(struct node) + sizeof(struct header)+sizeof(buffer_tail);
	}
}

void *memory_creation()
{
	int i, size=0, len=0;
	char *p;

	for(i=0 ; i < ROWS; i++)
		size = size + ( (mem_req[i][0] + sizeof(struct node) + sizeof(struct
		header)+sizeof(buffer_tail))*mem_req[i][1]);/*+ANOTHER*(mem_req[i][0]);*/

	printf("-------->sizeof structure is %lu\n",sizeof( struct node ));
	printf("-------->size of header is   %lu\n",sizeof( struct header ));
	printf("-------->size of tail is   %lu\n",sizeof( buffer_tail));
	printf("-------->size is %d\n",size);

	p = malloc(size);

	for(i = 0; i < ROWS; i++ )
	{
		populate_free_buff_list ( p+len, mem_req[i][0], (/*ANOTHER+*/mem_req[i][1]) );

		len = len + (( mem_req[i][0] + sizeof(struct node) + sizeof(struct
		header)+sizeof(buffer_tail))* mem_req[i][1]);
	}

	printf("------->the value of len is %d\n",len);

	printf("\n");

}


main()
{
	char *q1,*q2;
	char *q3;

	memory_creation();

	q1=amalloc(100);
	printf("--------->the value of amlloc is %p\n",q1);
	sleep(2);

	q2=amalloc(100);
	printf("--------->the value of q2 amlloc is %p\n",q2);
	sleep(2);
	//afree(q2);

	q3 = amalloc(100);
	printf("--------->the value of q3 amlloc is %p\n",q3);

	display();
	display_data();
}
