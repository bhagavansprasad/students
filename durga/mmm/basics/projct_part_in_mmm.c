#include <stdlib.h>
#include <string.h>
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

struct header
{
	int num_buf;
	int totl_allocs;
	int totl_fress;
	int num_avil;
	int num_dubl_fress;
	int peak_usg;
	int num_mis;
	struct node *h;
};

#define EXTRA 3
#define UNIQUE_STRING "#S^I"

int i, j = 0;
char *p ;
int size  =0;
int alloc;
int fre;
int avalibul;
int peak = 0;
int *size_hadr;
char* tile_buf;

int	memory_requir[3][2] = { 
	{100,2},
	{200,3},
	{300,4} 
};

struct header  head[sizeof(memory_requir)/sizeof(memory_requir[0])];


/*function for display for data base*/

void display_data(void)
{
	int k;


	for(k=0; k<  sizeof(memory_requir)/sizeof(memory_requir[0]) ; k++)
	{
		printf("the num of bufs in head[%d].num_buf         %d\n", k, head[k].num_buf);
		printf("the num of bufs in head[%d].totl_allocs     %d\n", k, head[k].totl_allocs);
		printf("the num of bufs in head[%d].totl_fress      %d\n", k, head[k].totl_fress);
		printf("the num of bufs in head[%d].num_avil        %d\n", k, head[k].num_avil);
		printf("the num of bufs in head[%d].num_dubl_fress  %d\n", k,head[k].num_dubl_fress);
		printf("the num of bufs in head[%d].num_mis         %d\n", k, head[k].num_mis);
		printf("the num of bufs in head[%d].peak_usg         %d\n", k,head[k].peak_usg);
		printf("\n");
	}
}




/*function for konwing the function reuirement*/

int get_memory_size()
{
	for (i = 0 ; i<sizeof(memory_requir)/sizeof(memory_requir[0]); i++)
		size +=(((memory_requir[i][0]+sizeof(struct node)+sizeof(int)+sizeof( UNIQUE_STRING)))*memory_requir[i][1]) + EXTRA*(memory_requir[i][0]);
	printf("print the size of unique string %d\n", sizeof( UNIQUE_STRING));
	return size;
}

/*function for creating the list of free buffers*/


void cret_free_buf_list(char* p,int size_buf,int val)
{
	int len =0,k;

	for(k = 0; k<val; k++)
	{
		hash_list(p+len, size_buf,val);
		len = len +size_buf+sizeof(struct node)+sizeof(int);
	}
}

/* function for hash_list creation*/

int hash_list (void* pt, int size_buf,int num_bufs)
{
	struct node* temp,*new;
	int k;

	new = (struct node*)pt;
	size_hadr = pt+sizeof(struct node);
	tile_buf = pt+sizeof(struct node)+sizeof(int)+ size_buf;
	//	printf("--->print the recevd address in hash list %u\n", pt);
	//	printf("--->print the addres in size_hadr %u\n", size_hadr);
	//	printf("--->print the addres in tile_buf %u\n", tile_buf);

	*size_hadr = size_buf;

	new->flag =0;
	new->p = pt+sizeof(struct node)+sizeof(int);
	//	printf("--->print the addres in new->p %u\n", new->p);
	new->pid = 0;
	new->curr_time = 0;
	new->next = NULL;

	strcpy(tile_buf,  "#S^I");
	printf("the string in the tile_buf is %u\t%s\n", tile_buf,tile_buf);
		printf("------>the size of each node is %d\n",	*size_hadr);
	printf("\n");

	k = get_key(size_buf);

	temp = head[k].h;
	head[k].num_buf = num_bufs;
	//printf("\n------>>>pritn the num of bufs head[%d].num_bufs------->>%d\n",k,head[k].num_buf);
	if(head[k].h == NULL)
	{
		head[k].h = new;
		return 0;
	}

	for(temp=head[k].h ;temp->next!= NULL;temp = temp->next);
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
	struct tm *tp;
	struct node* temp;
	int k; 
	char*ts;

	k = get_key(size);

	temp = head[k].h;
	while(temp != NULL)
	{
		if( temp->flag == 0)
		{ 
			//printf("----->>print the j value in amalloc %d\n", j);
			j++;
			//	printf("----->>print the j value in amalloc %d\n", j);
			if(peak <= j )
			{
				peak = j;
				head[k]. peak_usg = peak;
			}

			head[k].totl_allocs++;
			//printf("print the p value in head[k].peak_usg amalloc %d\n",head[k].peak_usg);

			temp->pid = get_pid();
			time(&(temp->curr_time));
			tp = localtime(&(temp->curr_time));
			ts = asctime(tp);

			//printf("%p\n", temp->p);
			//printf("%ld\n", temp->curr_time);
			//printf("%d\n", temp->pid);
			//printf("%s\n", ts);
			head[k].num_avil = head[k].num_buf - head[k].totl_allocs;
			//printf("------>>> the num of avalibule bufss are head[%d].num_avil : %d\n", k, head[k].num_avil);

			temp->flag = 1;
			//printf("------->> the num of allocs arehead[%d]------> %d\n",k, head[k].totl_allocs);
			return (void*)temp->p;

		}

		temp = temp->next;
	} 

	head[k].num_mis++;
	//	printf("------->> the num of miss hapend arehead[%d]------> %d\n",k,head[k].num_mis);
	return NULL;

}

/*function for freening the memory*/

int afree(void * ptr)
{
	int key;
	struct node* temp;
	int *sub;
	char* test;

	sub = ptr- sizeof(int);
	test = (char *)ptr + *sub;
	printf("------> print the address in ptr in afree function %u\n", ptr);
	printf("------> print the address in test in afree function %u\n", test);
	printf("------> print the  test in afree function %s\n", test);
	printf("---->the value of sub in afree is %d\n",*sub);
	key = get_key(*sub);
	temp = head[key].h;


	while(temp != NULL)
	{
		if(ptr == temp->p)
		{
			if(temp->flag == 1)
			{
				head[key].totl_fress++;
				temp->flag = 0;
				j = 0;
				//		printf("---->>> total num of fress are head[%d].totl_fress %d\n",key,head[key].totl_fress);
				return 0;
			}
			else 
				head[key].num_dubl_fress++;
			//		printf("---->>> total num of double  fress are head[%d].totl_fress	%d\n",key,head[key].num_dubl_fress);

		}
		temp = temp->next;
	} 
}
/*function for display*/

void display(void)
{
	printf("\n------->>>dispaly under working---------->>>>>\n");
	struct node *t;
	int k;
	printf("node		next_node		address 		pid		time\n");

	for(k=0; k<  sizeof(memory_requir)/sizeof(memory_requir[0]) ; k++)
	{
		if(head[k].h!=NULL)
		{
			char buf[25];
			t = head[k].h;
			for(t=head[k].h;t!=NULL;t=t->next)
			{
				strcpy(buf,ctime(&(t->curr_time)));
				//	printf("%p\t", t);
				//	printf("%p\t\t",t->next);
				//	printf("%p\t\t", t->p);
				//	printf("%d\t\t", t->pid);
				//	printf("%ld\t", t->curr_time);
				//	printf(" %s\n",buf);
				//printf("print the p value in head[k].peak_usg display %d\n",head[k].peak_usg);
				printf("print the tile data in the node %u\n", t->p+(memory_requir[k][0]));
			}

			printf("\n");
		}
	}
}




#if 0
void get_instruments()
{
	for(i=0;i < sizeof(memory_requir)/sizeof(memory_requir[0]);i++)
	{
		head[i].num_buf = memory_requir[i][1];
		head[i].totl_allocs = alloc;
		head[i].totl_fress = fre;
		head[i].num_avil = head[i].num_buf - alloc;
		printf("-----> print the num_buf head[%d]--->%d\n",i, head[i].num_buf);
		printf("-----> print the totl_allocs head[%d]--->%d\n",i, head[i].totl_allocs);
		printf("-----> print the totl_fress head[%d]--->%d\n",i, head[i].totl_fress);
		printf("-----> print the avalibul head[%d]--->%d\n",i, head[i].num_avil);
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
		cret_free_buf_list( p+len,memory_requir[i][0],(memory_requir[i][1]+EXTRA));

		len =  len+((memory_requir[i][0]+sizeof(struct node)+sizeof(int))*memory_requir[i][1]);
	}

	p1 = amalloc(200);
	printf("address retun by the amalloc is %p\n", p1);
	sleep(1);

	p2 = amalloc(100);
	printf("address retun by the amalloc is %p\n", p2);
	sleep(2);

	p3 = amalloc(100);
	printf("address retun by the amalloc is %p\n", p3);

	afree(p1);
	char *p5 = amalloc(300);
	afree(p1);

	p4 = amalloc(100);
	printf("address retun by the amalloc is %p\n", p4);

	display();
	//	display_data();
}

