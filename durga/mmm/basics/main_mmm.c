#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct node
{
	int flag;
	void* p;
	int pid;
	time_t curr_time;
	struct node* next;
};

int i, j;
char *p ;
int size  =0;
int	memory_requir[3][2] = { 
	{100,2},
	{200,3},
	{300,4} 
};

void display(void);
void fun(void);
int get_key(void* pt);
int hash_list (void* pt);
void memory_allocate(void);
int get_key(int );
int hash_list (void*, int );
int get_memory_size(void);
void cret_free_buf_list(char* ,int,int);

main()
{
	memory_allocate();
	printf("adress retrun by malloc is %p\n\a",p);
	for (i = 0; i<9; i++)
	{
		printf("address in ptr[%d]is : %p\n", i, ptr[i]);
		hash_list(ptr[i]);
	}
	display();

}

/*function for memory allocation*/
void memory_allocate(void)
{
	int	arr[3][2] = { 
		{100,2},
		{200,3},
		{300,4} 
	};
	size = get_memory_size();
	p = (char *)malloc(size);

	printf("size that is creatd is %d\n",size);
	printf("adress retrun by malloc is %u\n",p);
	int len=0;
for(i=0;i<3;i++)
{
	  cret_free_buf_list( p+len,memory_requir[i][0],memory_requir[i][1]);
		len =  len+((memory_requir[i][0]+sizeof(struct node)+sizeof(int))*memory_requir[i][1]);
		}
	display();

}

struct node* h[sizeof(memory_requir)/sizeof(memory_requir[0])] ={NULL};
int *size_hadr;


/*function for konwing the function reuirement*/

int get_memory_size()
{
	for (i = 0 ; i<sizeof(memory_requir)/sizeof(memory_requir[0]); i++)
		size +=((memory_requir[i][0]+sizeof(struct node)+sizeof(int))*memory_requir[i][1]);

	return size;
}

/*function for creating the list of free buffers*/


}



void cret_free_buf_list(char* p,int size_buf,int val)
{
	int len =0,k;

	for(k = 0; k<val; k++)
	{
		hash_list(p+len, size_buf);
		len = len +size_buf+sizeof(struct node)+sizeof(int);
	}

}

/* function for hash_list creation*/

int hash_list (void* pt, int size_buf)
{
	struct node* temp,*new;
	int k;

	new = (struct node*)pt;
	size_hadr = pt+sizeof(struct node);
	*size_hadr = size_buf;


	new->flag =0;
	new->p = pt+sizeof(struct node)+sizeof(int);
	new->pid = 0;

	new->curr_time = 0;
	new->next = NULL;

	k = get_key(size_buf);

	temp = h[k];

	if(h[k] == NULL)
	{
		h[k] = new;
		return 0;
	}

	for(temp=h[k];temp->next!= NULL;temp = temp->next);
	temp->next = new;

	return 0;

}

/*function for get_key for hesh table genration*/

int get_key(int size_buf)
{
	int k;

	for( k= 0; k < sizeof(memory_requir)/sizeof(memory_requir[0]); k++)
	{
		if(size_buf == memory_requir[k][0])
			return k;

	}
	return -1;
}

/*function for get_pid is*/
int get_pid(void)
{
	return getpid();
}

/*function for amalloc */

void* amalloc(int size)
{

	struct node* temp;
	int k; 

	k = get_key(size);

	temp = h[k];
	while(temp != NULL)
	{
		if( temp->flag == 0)
		{
			if(i>=0 && i<= 1)
			{
				printf("--->value of i is %d\n",i);
				printf("address in ptr[%d]is : %p\n", i, ptr[i]);
				return 0;
			}
			else if(i>=2 && i<= 4)
			{
				printf("--->value of i is %d\n",i);
				printf("address in ptr[%d]is : %p\n", i, ptr[i]);
				return 1;
			}
			else 
			{
				printf("--->value of i is %d\n",i);
				printf("address in ptr[%d]is : %p\n", i, ptr[i]);
				return 2;
			}
			printf("the value of j is %d\n",u);
			return u;
			temp->pid = get_pid();
			time(&(temp->curr_time));
			ctime(&(temp->curr_time));
			printf("%p\n", temp->p);
			printf("%ld\n", temp->curr_time);
			printf("%d\n", temp->pid);

			temp->flag = 1;

			return (void*)temp->p;

		}
		temp = temp->next;
	}
	return NULL;

}

/*function for freening the memory*/

int afree(void * ptr)
{
	int key;
	struct node* temp;
	int *sub;

	sub = ptr- sizeof(int);

	key = get_key(*sub);
	temp = h[key];
	
	while(temp != NULL)
	{
		if(ptr == temp->p)
		{
			temp->flag = 0;
			return 0;
		}
		temp = temp->next;
	}
}
/*function for display*/

void display(void)
{
	struct node *t;
	int k;
	printf("node		next_node		address 		pid		time\n");

	for(k=0; k<  sizeof(memory_requir)/sizeof(memory_requir[0]) ; k++)
	{
		if(h[k]!=NULL)
		{
			t = h[k];
			for(t=h[k];t!=NULL;t=t->next)
			{
				printf("%p\t\t", t);
				printf("%p\t\t",t->next);
				printf("  %p\t\t", t->p);
			   printf("%d\n", t->pid);
			   printf("%ld\t\t", t->curr_time);
			}

			printf("\n");
		}
	}
}

/*function for display for data base*/
#if 0
void display_data(void)
{
	struct node *t;
	int k;
	printf("flag	address			pid			time\n");
	for(k=0; k<  sizeof(memory_requir)/sizeof(memory_requir[0]) ; k++)
	{
		if(h[k]!=NULL)
		{
			t = h[k];
			for(t=h[k];t!=NULL;t=t->next)
			{
				printf(" %d\t", t->flag);
				printf("%p\t\t", t->p);
				printf(" %d\t\t", t->pid);
				printf(" %d\n", t->curr_time);
			}

			printf("\n");
		}
		printf("\n");
	}
}
#endif


/*this is the main function */

main()
{
	int len=0;
	void *p1,*p2,*p3, *p4;

	size = get_memory_size();
	p = (char *)malloc(size);

	struct node s;
	printf("size that is creatd is %d\n",size);
	printf("adress retrun by malloc is %p\n",p);

	for(i=0;i < sizeof(memory_requir)/sizeof(memory_requir[0]);i++)
	{
		cret_free_buf_list( p+len,memory_requir[i][0],memory_requir[i][1]);

		len =  len+((memory_requir[i][0]+sizeof(struct node)+sizeof(int))*memory_requir[i][1]);
	}
	display();

	p1 = amalloc(200);
	printf("address retun by the amalloc is %p\n", p1);
	sleep(1);

	p2 = amalloc(100);
	printf("address retun by the amalloc is %p\n", p2);
	sleep(2);

	p3 = amalloc(100);
	printf("address retun by the amalloc is %p\n", p3);

	afree(p1);

	p4 = amalloc(200);
	printf("address retun by the amalloc is %p\n", p4);
	
       display();
}


