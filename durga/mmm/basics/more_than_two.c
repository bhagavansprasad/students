#include <stdio.h>
int flag[4] = {0};
char buf[4][100];
void* amalloc(int );
int afree(void* );
main()
{
	int *p1[4], *p2[4];
	int i;
	for(i = 0; i<4; i++)
	{
		printf("address of the buf is buf[%d]is %u\n",i, buf[i]);

	}

	p1[0] = amalloc(100);
	printf("content present in p1[0]%u\n", p1[0]);

	p1[1] = amalloc(100);
	printf("content present in p1[1]%u\n", p1[1]);

	p1[2] = amalloc(100);
	printf("content present in p1[2]%u\n", p1[2]);


	p1[3] = amalloc(100);
	printf("content present in p1[3]%u\n", p1[3]);
    afree(p1[0]);
  
	p2[0] = amalloc(100);
	printf("content present in p2[0]%u\n", p2[0]);
}




void* amalloc(int size)
{
	 int i;
	 for (i = 0; i<4 ; i++ )
	 {
	 	if(flag[i] == 0)
		{
			flag[i] = 1;
			return ((void*)buf[i]);
		}
	 }
	 return NULL;

}

int  afree(void *p)
{
	int i;
	for(i = 0; i<4; i++)
	{
		if(p == buf[i] )
		{
			flag[i] = 0;
			return 0;
		}

	}
	printf("free is failed, send the proper address\n");
}
